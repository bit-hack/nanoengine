#pragma once

#include "nodes.h"
#include "../scenegraph.h"


struct node_null_t : public sg_object_t {

  static const uint32_t TYPE = node_type_null_t;
};
