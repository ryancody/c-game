#include "cursor.h"
#include "global.h"
#include <math.h>
#include <raylib.h>
#include <raymath.h>

Cursor CreateCursor() {
  Cursor c = {0};
  c.rect = (Rectangle){0, 0, GRID_SIZE, GRID_SIZE};
  return c;
}

void UpdateCursor(Cursor *cursor) {
  Vector2 mousePos = GetMousePosition();
  cursor->rect.x = floorf(mousePos.x / GRID_SIZE) * GRID_SIZE;
  cursor->rect.y = floorf(mousePos.y / GRID_SIZE) * GRID_SIZE;
}

void DrawCursor(Cursor *cursor) { DrawRectangleLinesEx(cursor->rect, 3, RED); }
