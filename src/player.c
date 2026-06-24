#include "player.h"
#include <raylib.h>
#include <raymath.h>

#define MOVE_SPEED 200.0f

Player CreatePlayer(float x, float y) {
  Player p = {0};
  p.rect = (Rectangle){x, y, 40, 40};
  return p;
}

void UpdatePlayer(Player *player, float dt) {
  player->velocity.x = 0;
  player->velocity.y = 0;

  if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
    player->velocity.x = 1;
  if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
    player->velocity.x = -1;
  if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))
    player->velocity.y = 1;
  if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))
    player->velocity.y = -1;

  Vector2 dir = Vector2Normalize(player->velocity);

  dir = Vector2Scale(dir, MOVE_SPEED);

  player->rect.x += dir.x * dt;
  player->rect.y += dir.y * dt;
}

void DrawPlayer(Player *player) {
  DrawRectangle((int)player->rect.x, (int)player->rect.y,
                (int)player->rect.width, (int)player->rect.height, BLUE);
}
