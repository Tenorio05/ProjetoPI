#ifndef GAME_H
#define GAME_H

#include "raylib.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

typedef struct Player {
    Rectangle rect;
    Color color;
    float angle;
} Player;

typedef struct Enemy {
    Rectangle rect;
    Color color;
    float speed;
    char word[50];
    int health;
    int index_typing;
    int locked;
    float delay_speed;
    int texture_index;
    float angle;

} Enemy;

typedef struct Projectile {
    Vector2 center;
    Enemy target;
    float speed;
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

// Menu & Settings
typedef struct Button {
    Rectangle rec;
    char text[20];
    Color rec_color, text_color;
} Button;

typedef struct Line {
    float x, y;
    float size;
    Color color;
} Line;

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

extern Sound botaoSound;
extern Sound morteSound;
extern Sound tiroSound;
extern Sound menuJogoSound;

// Menu & Settings & Credits
Rectangle rec = {(SCREEN_WIDTH - 400)/2, (SCREEN_HEIGHT - 80)/2, 400, 80};
int font_size = 50;
Button back = {{(SCREEN_WIDTH - 33*5)/2, SCREEN_HEIGHT/2 + 220, 33*5, 50}, "Voltar", BLACK, RAYWHITE};

// game.c
void DrawGame(Player* player, EnemyList* enemy_list, ProjectileList* projectile_list, Font myfont);
void UpdateGameplay(Player* player, EnemyList* enemy_list, ProjectileList* projectile_list);

// enemy.c
void InitTexts(void);
void DrawEnemies(EnemyList* enemy_list, Font myfont, Texture2D enemyTextures[]);
void SpawnEnemy(EnemyList* enemy_list);
void UpdateEnemyWaves(EnemyList* enemy_list);
void MoveEnemies(EnemyList* enemy_list, Player* player);
void RemoveEnemy(EnemyList* enemy_list, int index_enemy);
void DelayEnemies(EnemyList* enemy_list);
bool IsPositionFree(EnemyList* enemy_list, Rectangle new_enemy_rect);

// menu.c
void SetMenu(void);
void DrawMenu(void);
void UpdateMenu(void);

//settings.c
void SetSettings(void);
void DrawSettings(void);
void UpdateSettings(void);

//credits.c
void SetCredits(void);
void DrawCredits(void);
void UpdateCredits(void);

// player.c
void CreatePlayer(Player* player);
void DrawPlayer(Player* player);
void TurnToEnemy(Player* player, EnemyList* enemy_list);

// typing.h
void HandleTyping(Player* player, EnemyList* enemy_list, ProjectileList* projectile_list, int key_pressed);

// projectile.c
void UpdateProjectile(ProjectileList* projectile_list, EnemyList* enemy_list);
void DrawProjectiles(ProjectileList* projectile_list);
void CreateProjectile(ProjectileList* projectile_list, Player* player, EnemyList* enemy_list, int index_enemy);


#include "screens/game.c"
#include "entities/enemy.c"
#include "screens/menu.c"
#include "screens/settings.c"
#include "screens/credits.c"
#include "entities/player.c"
#include "typing.c"
#include "entities/projectile.c"
#endif

