#pragma once

#include "nodes.h"
#include "../scenegraph.h"


struct node_script_t : public sg_object_t {

  static const uint32_t TYPE = node_type_script_t;

  virtual void run() = 0;
};
