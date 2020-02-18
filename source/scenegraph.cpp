#include "scenegraph.h"


void sg_object_t::detach() {
  if (parent) {
    parent->child_remove(this);
    parent = nullptr;
  }
}

void sg_object_t::child_add(sg_object_t *obj) {
  assert(obj);
  assert(obj->parent == nullptr);
  child.push_back(obj);
  obj->parent = this;
}

void sg_object_t::child_remove(sg_object_t *obj) {
  assert(obj);
  for (auto itt = child.begin(); itt != child.end(); ++itt) {
    sg_object_t *c = *itt;
    assert(c->parent = this);
    if (*itt == obj) {
      c->parent = nullptr;
      child.erase(itt);
      return;
    }
  }
}

bool sg_object_t::child_has(sg_object_t *obj) {
  assert(obj);
  for (auto itt = child.begin(); itt != child.end(); ++itt) {
    if (*itt == obj) {
      return true;
    }
  }
  return false;
}

sg_object_t *sg_object_t::child_find(const std::string &name) {
  for (auto itt = child.begin(); itt != child.end(); ++itt) {
    sg_object_t *obj = *itt;
    if (obj->name == name) {
      return obj;
    }
  }
  return nullptr;
}

size_t sg_object_t::child_count() const {
  return child.size();
}

void sg_object_t::enumerate(
  const sg_object_t *obj,
  std::vector<const gc_object_t *> &pending) {
  assert(obj);
  for (const sg_object_t *c : obj->child) {
    pending.push_back(c);
  }
}
