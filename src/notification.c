#include "notification.h"
#include "global.h"
#include <stdio.h>

Notification CreateNotification(const char *msg, float time) {
  Notification n = {0};
  snprintf(n.message, sizeof(n.message), "%s", msg);
  n.time = time;
  n.timer = time;
  return n;
}

void UpdateTimer(Notification *notification, float dt) {
  notification->timer -= dt;
}

void DrawNotification(Notification *n) {
  float alpha = n->time / n->timer;
  DrawText(TextFormat("pos: %.0f %.0f", n->pos.x, n->pos.y), n->pos.x, n->pos.y,
           FONT_SIZE, Fade(BLACK, alpha));
}
