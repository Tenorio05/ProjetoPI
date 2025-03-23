#ifndef TYPING_H
#define TYPING_H

#include "enemy.h"

typedef enum StateTyping {NOTLOCKED = 0, LOCKONENEMY = 1} StateTyping;
extern StateTyping state;

void HandleTyping(EnemyList* enemy_list, int key_pressed);

#include "typing.c"
#endif

