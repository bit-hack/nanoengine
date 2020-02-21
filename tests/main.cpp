#include "../source/engine.h"
#include "../source/nodes/nodes.h"
#include "../source/nodes/node_sprite.h"


int main(int argc, char **args) {

  engine_t engine;

  if (!engine.init()) {
    return 1;
  }

  auto & gc = engine.gc();
  engine.scenegraph().root = gc.alloc<node_sprite_t>();

  assert(engine.scenegraph().root->is_a<node_sprite_t>());

  while (engine.is_active()) {
    engine.tick();
  }

  return 0;
}
