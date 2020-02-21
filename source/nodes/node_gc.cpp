#include "node_null.h"
#include "node_script.h"
#include "node_sprite.h"
#include "node_tilemap.h"

#include "../gc.h"

void node_gc_init(gc_t &gc) {
  gc.add_enum(node_type_null,    sg_object_t::enumerate);
  gc.add_enum(node_type_object,  sg_object_t::enumerate);
  gc.add_enum(node_type_script,  sg_object_t::enumerate);
  gc.add_enum(node_type_sprite,  sg_object_t::enumerate);
  gc.add_enum(node_type_tilemap, sg_object_t::enumerate);
  gc.add_enum(node_type_aabb,    sg_object_t::enumerate);
}
