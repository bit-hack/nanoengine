#pragma once

#include "nodes.h"
#include "../scenegraph.h"


struct node_tilemap_t : public sg_object_t {

  node_tilemap_t()
    : sg_object_t(RTTI) {
  }

  void draw();

  static gc_rtti_t RTTI;
};
