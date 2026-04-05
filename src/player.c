#include "player.h"
#include <raylib.h>

#define GRAVITY 800.0f
#define JUMP_FORCE -400.0f
#define MOVE_SPEED 200.0f

Player CreatePlayer(float x, float y) {
  Player p = {0};
  p.rect = (Rectangle){x, y, 40, 40};
  return p;
}

void UpdatePlayer(Player *player) {
  float dt = GetFrameTime();

  if (IsKeyDown(KEY_RIGHT))
    player->velocity.x = MOVE_SPEED;
  else if (IsKeyDown(KEY_LEFT))
    player->velocity.x = -MOVE_SPEED;
  else
    player->velocity.x = 0;

  player->velocity.y += GRAVITY * dt;
  player->rect.x += player->velocity.x * dt;
  player->rect.y += player->velocity.y * dt;

  if (player->rect.y >= 500) {
    player->rect.y = 500;
    player->velocity.y = 0;
    player->isGrounded = true;

    if (IsKeyPressed(KEY_SPACE)) {
      player->velocity.y = JUMP_FORCE;
      player->isGrounded = false;
    }
  }
}

void DrawPlayer(Player *player) {
  DrawRectangle((int)player->rect.x, (int)player->rect.y,
                (int)player->rect.width, (int)player->rect.height, BLUE);
}
