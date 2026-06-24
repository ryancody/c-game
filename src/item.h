#ifndef ITEM_H
#define ITEM_H

#include <raylib.h>

typedef struct {
  Rectangle rect;
  Vector2 velocity;
} Item;

Item CreateItem(float x, float y, float width, float height);
void DrawItem(Item *item);

#endif
