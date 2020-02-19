#include "engine.h"
#include "nodes/nodes.h"

#include "nodes/node_sprite.h"


int main(int argc, char **args) {

  engine_t engine;

  if (!engine.init()) {
    return 1;
  }

  auto & gc = engine.gc();
  engine.scenegraph().root = gc.alloc<node_sprite_t>();

  while (engine.is_active()) {
    engine.tick();
  }

  return 0;
}
