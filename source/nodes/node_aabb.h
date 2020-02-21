#pragma once

#include "nodes.h"
#include "../scenegraph.h"


struct node_aabb_t : public sg_object_t {

  node_aabb_t()
    : sg_object_t(RTTI) {
  }

  // collision mask
  uint32_t mask;
  // bounds
  float x0, y0, x1, y1;

  static gc_rtti_t RTTI;
};
