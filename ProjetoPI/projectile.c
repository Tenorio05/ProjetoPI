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

void CreateProjectile(ProjectileList* projectile_list, Player* player) {
    Projectile projectile;
    projectile.center = (Vector2) {player->position.x + player->width / 2, player->position.y - player->height - 10};
    projectile.radius = 3;
    int qty_projectiles = projectile_list->qty_projectiles;
    
    projectile_list->projectiles[qty_projectiles] = projectile;
    projectile_list->qty_projectiles++;
}