#pragma once

enum {
  node_type_object,

  node_type_script,
  node_type_sprite,
  node_type_null,
  node_type_tilemap,
  node_type_aabb,

  _NODE_COUNT_
};

extern void node_gc_init(struct gc_t &gc);
