#include "raylib.h"
#include "game.h"
#include "stdio.h"


void DrawProjectiles(ProjectileList* projectile_list) {
    int qty_projectiles = projectile_list->qty_projectiles; 
    for (int i = 0; i < qty_projectiles; i++) {
        Projectile projectile = projectile_list->projectiles[i];
        DrawCircle(projectile.center.x, projectile.center.y, projectile.radius, BLUE);
    }
}

void UpdateProjectile(ProjectileList* projectile_list) {

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
    Vector2 player_center = {player->position.x + player->width / 2, player->position.y - player->height / 2};
    
    float dx = player_center.x - enemy_center.x;
    float dy = player_center.y - enemy_center.y;

    Projectile projectile;
    projectile.center = (Vector2) {player_center.x - ((dx / dy) * 40), player_center.y - 40};
    projectile.radius = 2;
    int qty_projectiles = projectile_list->qty_projectiles;
    
    projectile_list->projectiles[qty_projectiles] = projectile;
    projectile_list->qty_projectiles++;
}