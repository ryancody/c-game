#include "item.h"
#include <raylib.h>

Item CreateItem(float x, float y, float width, float height) {
  Item i = {0};
  i.rect = (Rectangle){x, y, width, height};
  return i;
}

void DrawItem(Item *item) {
  DrawRectangle((int)item->rect.x, (int)item->rect.y, (int)item->rect.width,
                (int)item->rect.height, RED);
}
