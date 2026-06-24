#ifndef CURSOR_H
#define CURSOR_H

#include <raylib.h>

typedef struct {
  Rectangle rect;
} Cursor;

Cursor CreateCursor();
void UpdateCursor(Cursor *cursor);
void DrawCursor(Cursor *cursor);

#endif
