#include "platform.h"
#include <raylib.h>

Platform CreatePlatform(float x, float y, float width, float height) {
  Platform p = {0};
  p.rect = (Rectangle){x, y, width, height};
  return p;
}

void DrawPlatform(Platform *platform) {
  DrawRectangle((int)platform->rect.x, (int)platform->rect.y,
                (int)platform->rect.width, (int)platform->rect.height, BLUE);
}
