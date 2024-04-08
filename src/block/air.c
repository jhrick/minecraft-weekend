#include "block.h"

void air_init(void) {
  struct Block air = BLOCK_DEFAULT;
  air.id = AIR;
  air.transparent = true;
  air.solid = false;
  BLOCKS[AIR] = air;
}
