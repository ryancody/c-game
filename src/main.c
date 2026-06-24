#include "cursor.h"
#include "notification.h"
#include "player.h"
#include <raylib.h>

void HandleInput();

int main(void) {
  InitWindow(800, 600, "C Game");
  SetTargetFPS(60);

  for (int i = 0; i < 4; i++) {
    TraceLog(LOG_INFO, "Gamepad %d available: %d", i, IsGamepadAvailable(i));
  }

  Player player = CreatePlayer(100, 400);
  Cursor cursor = CreateCursor();
  NotificationList notificationList = {0};

  while (!WindowShouldClose()) {
    float dt = GetFrameTime();

    HandleInput();

    UpdatePlayer(&player, dt);
    UpdateCursor(&cursor);

    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawPlayer(&player);
    DrawCursor(&cursor);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}

void HandleInput() {
  if (IsMouseButtonPressed(0)) {
    Notification n = CreateNotification("mouse clicked", 3);
  }
}
