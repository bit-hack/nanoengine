#pragma once

#include "nodes.h"
#include "../scenegraph.h"


struct node_script_t : public sg_object_t {

  node_script_t()
    : sg_object_t(RTTI) {
  }

  static gc_rtti_t RTTI;

  virtual void run() = 0;
};
