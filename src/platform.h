#ifndef PLATFORM_H
#define PLATFORM_H

#include <raylib.h>

typedef struct {
  Rectangle rect;
  Vector2 velocity;
} Platform;

Platform CreatePlatform(float x, float y, float width, float height);
void DrawPlatform(Platform *platform);

#endif
