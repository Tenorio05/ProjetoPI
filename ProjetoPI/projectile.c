#include "raylib.h"
#include "game.h"
#include "stdio.h"
#include "math.h"


void DrawProjectiles(ProjectileList* projectile_list) {
    int qty_projectiles = projectile_list->qty_projectiles; 
    for (int i = 0; i < qty_projectiles; i++) {
        Projectile projectile = projectile_list->projectiles[i];
        DrawCircle(projectile.center.x, projectile.center.y, projectile.radius, BLUE);
    }
}

void UpdateProjectile(ProjectileList* projectile_list, EnemyList* enemy_list) {
    float dx, dy, distance;
    for (int i = 0; i < projectile_list->qty_projectiles; i++) {
        Projectile projectile = projectile_list->projectiles[i];
        Enemy enemy = projectile.target;
        dx = projectile.center.x - enemy.position.x;        
        dy = projectile.center.y - enemy.position.y;
        distance = sqrt(dx*dx + dy*dy);

        projectile_list->projectiles[i].center.x += (-dx / distance) * projectile.speed;
        projectile_list->projectiles[i].center.y -= (dy / distance) * projectile.speed;
        DrawText(TextFormat("%f", projectile_list->projectiles[i].center.x), 0, 0, 40, RED);
    }
}

void CreateProjectile(ProjectileList* projectile_list, Player* player, EnemyList* enemy_list) {
    int index_locked = -1;
    for (int i = 0; i < enemy_list->qty_enemies; i++) {
        if (enemy_list->enemies[i].locked) {
            index_locked = i;
            break;
        }
    }

    Enemy enemy = enemy_list->enemies[index_locked];
    Vector2 enemy_center = {enemy.position.x + enemy.width / 2, enemy.position.y - enemy.height / 2};
    
    float dx = player->position.x - enemy_center.x;
    float dy = player->position.y - enemy_center.y;

    Projectile projectile;
    projectile.center = (Vector2) {player->position.x - ((dx / dy) * 30), player->position.y - 30};
    projectile.radius = 2;
    projectile.target = enemy;
    projectile.speed = 5;
    
    int qty_projectiles = projectile_list->qty_projectiles;
    projectile_list->projectiles[qty_projectiles] = projectile;
    projectile_list->qty_projectiles++;
}