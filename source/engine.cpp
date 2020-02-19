#include "engine.h"

#include "nodes/node_script.h"
#include "nodes/node_sprite.h"
#include "nodes/node_tilemap.h"


void engine_visitor_t::on_object(sg_object_t *obj) {
  switch (obj->rtti.type) {
  case node_type_null:
    on_node_type_null(obj); break;
  case node_type_script:
    on_node_type_script(obj); break;
  case node_type_sprite:
    on_node_type_sprite(obj); break;
  case node_type_tilemap:
    on_node_type_tilemap(obj); break;
  default:
    assert(!"unknown node type");
  }
}

void engine_visitor_t::on_node_type_null(sg_object_t *obj) {
  // TODO
}

void engine_visitor_t::on_node_type_script(sg_object_t *obj) {
  node_script_t *s = obj->cast<node_script_t>();
  s->run();
}

void engine_visitor_t::on_node_type_sprite(sg_object_t *obj) {
  // TODO
}

void engine_visitor_t::on_node_type_tilemap(sg_object_t *obj) {
  // TODO
}

engine_t::engine_t()
  : active(false)
{}

bool engine_t::init() {
  gc_.reset(new gc_t);
  scenegraph_.reset(new sg_scenegraph_t);
  active = true;
  return true;
}

void engine_t::tick() {
  // walk the scene graph
  if (scenegraph_->root) {
    visitor_->walk(scenegraph_->root);
  }
  // tick the garbage collector
  gc_->check_in(scenegraph_->root);
  gc_->collect();
}
