#ifndef GAME_H
#define GAME_H

typedef struct Player {
    Vector2 position;
    float width;
    float height;
    float angle;
} Player;

typedef enum GameScreen {
    MENU = 0,
    GAMEPLAY = 1,
    SETTINGS = 2,
    CREDITS = 3,
    QUIT = 4
} GameScreen;

typedef struct Enemy {
    Vector2 position;
    float width;
    float height;
    float speed;
    char word[50];
    int index_typing;
    int locked;
} Enemy;

typedef struct EnemyList {
    Enemy enemies[20];
    int qty_enemies;
} EnemyList;

typedef enum StateTyping {
    NOTLOCKED = 0, 
    LOCKONENEMY = 1
} StateTyping;


extern GameScreen currentScreen;
extern StateTyping state;


void HandleTyping(Player* player, EnemyList* enemy_list, int key_pressed);

void DrawGame(Player* player, EnemyList* enemy_list, Font myfont);
void UpdateGameplay(Player* player, EnemyList* enemy_list);

void CreatePlayer(Player* player);
void DrawPlayer(Player* player);

void DrawMenu(void);
void DrawSettings(void);
void DrawCredits(void);
void UpdateMenu(void);
void UpdateSettings(void);
void UpdateCredits(void);

void InitTexts(void);
void DrawEnemies(EnemyList* enemy_list, Font myfont);
void SpawnEnemy(EnemyList* enemy_list);
void MoveEnemies(EnemyList* enemy_list, Player* player);
void RemoveEnemy(EnemyList* enemy_list, int index_enemy);
void TurnToEnemy(Player* player);

#include "game.c"
#include "enemy.c"
#include "player.c"
#include "menu.c"
#include "typing.c"

#endif