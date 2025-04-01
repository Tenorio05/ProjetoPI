#ifndef GAME_H
#define GAME_H

#include "raylib.h"

typedef struct Player {
    Vector2 position;
    float width;
    float height;
    float angle;
} Player;

typedef struct Enemy {
    Vector2 position;
    float width;
    float height;
    float speed;
    char word[50];
    int index_typing;
    int locked;
} Enemy;

typedef struct Projectile {
    Vector2 center;
    float radius;
} Projectile;

typedef struct ProjectileList {
    Projectile projectiles[50];
    int qty_projectiles;
} ProjectileList;

typedef struct EnemyList {
    Enemy enemies[20];
    int qty_enemies;
} EnemyList;

typedef enum GameScreen {
    MENU = 0,
    GAMEPLAY = 1,
    SETTINGS = 2,
    CREDITS = 3,
    QUIT = 4
} GameScreen;

typedef enum StateTyping {NOTLOCKED = 0, LOCKONENEMY = 1} StateTyping;

extern GameScreen currentScreen;
extern StateTyping state;


// game.c
void DrawGame(Player* player, EnemyList* enemy_list, ProjectileList* projectile_list, Font myfont);
void UpdateGameplay(Player* player, EnemyList* enemy_list, ProjectileList* projectile_list);

// enemy.c
void InitTexts(void);
void DrawEnemies(EnemyList* enemy_list, Font myfont);
void SpawnEnemy(EnemyList* enemy_list);
void MoveEnemies(EnemyList* enemy_list, Player* player);
void RemoveEnemy(EnemyList* enemy_list, int index_enemy);

// menu.c
void DrawMenu(void);
void DrawSettings(void);
void DrawCredits(void);
void UpdateMenu(void);
void UpdateSettings(void);
void UpdateCredits(void);

// player.c
void CreatePlayer(Player* player);
void DrawPlayer(Player* player);
void TurnToEnemy(Player* player, EnemyList* enemy_list);

// typing.h
void HandleTyping(Player* player, EnemyList* enemy_list, ProjectileList* projectile_list, int key_pressed);

// projectile.c
void UpdateProjectile(ProjectileList* projectile_list);
void DrawProjectiles(ProjectileList* projectile_list);
void CreateProjectile(ProjectileList* projectile_list, Player* player);


#include "game.c"
#include "enemy.c"
#include "menu.c"
#include "player.c"
#include "typing.c"
#include "projectile.c"
#endif