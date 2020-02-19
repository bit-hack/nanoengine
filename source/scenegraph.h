#pragma once
#include <vector>
#include <string>

#include "gc.h"
#include "nodes/nodes.h"


struct sg_object_t : public gc_object_t {

  sg_object_t(const gc_rtti_t &r)
    : gc_object_t(r)
    , enable(true)
    , parent(nullptr)
  {
  }

  sg_object_t(const gc_rtti_t &r, const std::string &n)
    : sg_object_t(r) {
    name = n;
  }

  // the name of this scene graphnode
  std::string name;

  // enable this scene graph node
  bool enable;

  // detach from the parent
  void detach();

  // add a child node
  void child_add(sg_object_t *obj);

  // remove a child node
  void child_remove(sg_object_t *obj);

  // return true if this object has a child
  bool child_has(sg_object_t *obj);

  // find a child by name
  sg_object_t *child_find(const std::string &name);

  // TODO: find extended child in the hierarchy

  // return the number of children
  size_t child_count() const;

  // garbage collection enumeration
  static void enumerate(
    const sg_object_t *,
    std::vector<const gc_object_t *> &);

  // return the children
  const std::vector<sg_object_t *> &children() const {
    return child;
  }

  // get the parent node
  // is root when nullptr is returned
  sg_object_t *owner() {
    return parent;
  }

  static gc_rtti_t RTTI;

protected:
  sg_object_t *parent;
  std::vector<sg_object_t *> child;
};

template <typename type_t>
struct sg_visitor_t {

  void walk(sg_object_t *obj) {
    assert(obj);

    static_assert(std::is_base_of<sg_visitor_t, type_t>::value,
                  "type must derive from sg_visitor_t");
    ((type_t*)this)->on_object(obj);

    // visit the children
    for (sg_object_t *c : obj->children()) {
      if (c->enable) {
        walk(c);
      }
    }
  }
};

struct sg_scenegraph_t {

  sg_scenegraph_t()
    : root(nullptr)
  {
  }

  sg_object_t *root;
};
