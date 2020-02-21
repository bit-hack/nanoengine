#pragma once
#include <memory>

#include "gc.h"
#include "scenegraph.h"


struct engine_visitor_t: public sg_visitor_t<engine_visitor_t> {

  void on_object(sg_object_t *obj);

  // delegate methods
  void on_node_type_null   (sg_object_t *obj);
  void on_node_type_script (sg_object_t *obj);
  void on_node_type_sprite (sg_object_t *obj);
  void on_node_type_tilemap(sg_object_t *obj);
  void on_node_type_aabb   (sg_object_t *obj);
};

struct engine_t {

  engine_t();

  bool init();

  void tick();

  sg_scenegraph_t &scenegraph() const {
    return *scenegraph_;
  }

  gc_t &gc() const {
    return *gc_;
  }

  bool is_active() const {
    return active;
  }

  void stop() {
    active = false;
  }

protected:
  bool active;

  std::unique_ptr<sg_scenegraph_t> scenegraph_;
  std::unique_ptr<gc_t> gc_;
  std::unique_ptr<engine_visitor_t> visitor_;
};
