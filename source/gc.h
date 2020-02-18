#pragma once

#include <cassert>
#include <vector>
#include <unordered_map>
#include <unordered_set>


struct gc_object_t;


typedef void (*gc_enumerate_t)(
  const gc_object_t *,
  std::vector<const gc_object_t *> &);


struct gc_object_t {
  gc_object_t(uint32_t t)
    : type(t) {
  }

  virtual ~gc_object_t() = default;

  template <typename type_t>
  bool is_a() const {
    return type == type_t::TYPE;
  }

  template <typename type_t>
  type_t *cast() {
    return is_a<type_t>() ? (type_t*)this : nullptr;
  }

  template <typename type_t>
  const type_t *cast() const {
    return is_a<type_t>() ? (const type_t*)this : nullptr;
  }

  const uint32_t type;
};


struct gc_t {

  template <class T, class... Types> T *alloc(Types &&... args) {
    // check allocation derives from gc_object_t
    static_assert(std::is_base_of<gc_object_t, T>::value,
                  "type must derive from gc_object_t");
    assert(0 != enums_.count(T::TYPE) && "GC enumrtator not defined");
    // perform the allocation and call constructor
    T *obj = new T(std::forward<Types>(args)...);
    // add to 'allocated' list
    allocs_.push_back(obj);
    return obj;
  }

  // perform a full sweep and collection
  void collect() {
    // visit everything
    while (!pending_.empty()) {
      // pop from the end of the pending list
      const gc_object_t *obj = pending_.back();
      pending_.pop_back();
      if (obj) {
        // if we have not visited this yet
        if (marked_.find(obj) == marked_.end()) {
          // mark it
          marked_.insert(obj);
          // enumerate its children
          auto itt = enums_.find(obj->type);
          assert(itt != enums_.end());
          itt->second(obj, pending_);
        }
      }
    }
    // delete redundant allocs
    for (auto itt = allocs_.begin(); itt != allocs_.end();) {
      if (marked_.find(*itt) == marked_.end()) {
        assert(*itt);
        delete *itt;
        itt = allocs_.erase(itt);
      } else {
        ++itt;
      }
    }
    // clear ready for next time
    pending_.clear();
    marked_.clear();
  }

  // check in a known live object
  void check_in(const gc_object_t *obj) {
    pending_.push_back(obj);
  }

  // add an enumeration function
  void add_enum(uint32_t type, gc_enumerate_t func) {
    assert(0 == enums_.count(type) && "GC enumerator already defined");
    enums_[type] = func;
  }

protected:

  // object enumeration functions
  std::unordered_map<uint32_t, gc_enumerate_t> enums_;

  // all objects that have been allocated
  std::vector<gc_object_t *> allocs_;

  // objects we have visited
  std::unordered_set<const gc_object_t *> marked_;
  // objects we need to visit
  std::vector<const gc_object_t *> pending_;
};
