#include "engine.h"
#include "nodes/nodes.h"


int main(int argc, char **args) {

  engine_t engine;

  if (!engine.init()) {
    return 1;
  }

  engine.tick();

  return 0;
}
