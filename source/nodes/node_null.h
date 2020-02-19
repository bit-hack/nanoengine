#pragma once

#include "nodes.h"
#include "../scenegraph.h"


struct node_null_t : public sg_object_t {

  node_null_t()
    : sg_object_t(RTTI) {
  }

  static gc_rtti_t RTTI;
};
