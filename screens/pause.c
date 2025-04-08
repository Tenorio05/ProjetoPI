#include "raylib.h"
#include "game.h"

Button pause, resume, settings, back_menu;

void SetPause(void) {
    pause.rec = (Rectangle) {rec.x - 30, rec.y - 240, rec.width, rec.height};
    strcpy(pause.text, "Pausado");  pause.text_color = RAYWHITE;
}

void DrawPause(void) {
    SetCredits();
    Texture2D background = LoadTexture("sprites/background.png");
    ClearBackground(BLACK);    
    DrawTexturePro(
        background,
        (Rectangle){0, 0, background.width, background.height},
        (Rectangle){0, 0, SCREEN_WIDTH, SCREEN_HEIGHT},
        (Vector2){ 0, 0 },
        0.0f,
        WHITE
    );

    DrawText(pause.text, (SCREEN_WIDTH - 77*5)/2, pause.rec.y + (pause.rec.height - 100)/2, 100, pause.text_color);
    DrawText(back.text,   (SCREEN_WIDTH - 33*5)/2, back.rec.y  + (back.rec.height - font_size)/2, font_size, back.text_color);

    if (CheckCollisionPointRec(GetMousePosition(), back.rec)) {
        DrawText(back.text, (SCREEN_WIDTH - 33*5)/2, back.rec.y  + (back.rec.height - font_size)/2, font_size, GRAY);
    }
}

void UpdatePause(Player *player, EnemyList *enemy_list, ProjectileList *projectile_list) {
    if (IsKeyPressed(KEY_ZERO)) {
        PlaySound(botaoSound); // Toca o som de botão
        currentScreen = GAMEPLAY;
    }
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), back.rec)) {
        ResetGame(player, enemy_list, projectile_list);
        PlaySound(botaoSound); // Toca o som de botão
        currentScreen = MENU;
    }
}
