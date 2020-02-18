#include "engine.h"
#include "scripts.h"


void engine_visitor_t::on_object(sg_object_t *obj) {
  switch (obj->type) {
  case sg_type_script_t:
    on_sg_type_script_t(obj); break;
  default:
    assert(!"unknown node type");
  }
}

void engine_visitor_t::on_sg_type_script_t(sg_object_t *obj) {
  sg_script_t *s = obj->cast<sg_script_t>();
  s->run();
}

bool engine_t::init() {
  gc_.reset(new gc_t);
  scenegraph_.reset(new sg_scenegraph_t);
  return true;
}

void engine_t::tick() {
  gc_->check_in(scenegraph_->root);
  gc_->collect();
}
