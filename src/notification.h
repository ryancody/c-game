#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include "global.h"
#include <raylib.h>

typedef struct {
  float timer;
  float time;
  Vector2 pos;
  char message[64];
} Notification;

Notification CreateNotification(const char *msg, float timer);
void UpdateTimer(Notification *notification, float dt);
void DrawTimer(Notification *notification);

typedef struct {
  Notification items[MAX_NOTIFICATIONS];
  int count;
} NotificationList;

void AddNotification(NotificationList *list, Notification *notification) {
  if (list->count >= MAX_NOTIFICATIONS)
    return;

  list->items[list->count++] = *notification;
}
#endif // !NOTIFICATION_H
