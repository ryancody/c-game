#include "player.h"
#include <raylib.h>

int main(void) {
  InitWindow(800, 600, "Platformer");
  SetTargetFPS(60);

  for (int i = 0; i < 4; i++) {
    TraceLog(LOG_INFO, "Gamepad %d available: %d", i, IsGamepadAvailable(i));
  }

  Player player = CreatePlayer(100, 400);

  while (!WindowShouldClose()) {
    UpdatePlayer(&player);

    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawPlayer(&player);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
