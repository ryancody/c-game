#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>

typedef struct {
  Rectangle rect;
  Vector2 velocity;
  bool isGrounded;
} Player;

Player CreatePlayer(float x, float y);
void UpdatePlayer(Player *player, float dt);
void DrawPlayer(Player *player);

#endif
