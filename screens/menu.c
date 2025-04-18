#include "raylib.h"
#include "game.h"
#include <string.h>

Button name, play, sett, cred, quit;

//DrawText("................................................................................................................................", 0, credit.rec.y - 10, 50, RED); // DEBUG
//DrawText("_____________________________________________________________________________________________", 0, credit.rec.y - 15, 50, RED); // DEBUG

void SetMenu(void) {
    play = (Button) {{rec.x, rec.y +  40, rec.width, rec.height}, "Jogar",         RAYWHITE, BLACK};
    sett = (Button) {{rec.x, rec.y + 130, rec.width, rec.height}, "Configurações", RAYWHITE, BLACK};
    cred = (Button) {{rec.x, rec.y + 220, rec.width, rec.height}, "Créditos",      RAYWHITE, BLACK};
    quit = (Button) {{rec.x, rec.y + 310, rec.width, rec.height}, "Sair",          RAYWHITE, BLACK};
}

void DrawMenu(void) {
    SetMenu();
    ClearBackground(BLACK);
    
    DrawTexturePro(background_menu,
    (Rectangle){ 0, 0, background_menu.width, background_menu.height },
    (Rectangle){ 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT },
    (Vector2){ 0, 0 },
    0.0f,
    WHITE);
    
    DrawRectangleRounded(play.rec, 0.5, 10, play.rec_color);
    DrawRectangleRounded(sett.rec, 0.5, 10, sett.rec_color);
    DrawRectangleRounded(cred.rec, 0.5, 10, cred.rec_color);
    DrawRectangleRounded(quit.rec, 0.5, 10, quit.rec_color);
    
    DrawText(play.text, (SCREEN_WIDTH - 28*5)/2, play.rec.y + (play.rec.height - font_size)/2, font_size, play.text_color);
    DrawText(sett.text, (SCREEN_WIDTH - 73*5)/2, sett.rec.y + (sett.rec.height - font_size)/2, font_size, sett.text_color);
    DrawText(cred.text, (SCREEN_WIDTH - 43*5)/2, cred.rec.y + (cred.rec.height - font_size)/2, font_size, cred.text_color);
    DrawText(quit.text, (SCREEN_WIDTH - 19*5)/2, quit.rec.y + (quit.rec.height - font_size)/2, font_size, quit.text_color);
    
    if (CheckCollisionPointRec(GetMousePosition(), play.rec)) {
        DrawRectangleRounded(play.rec, 0.5, 10, play.text_color);
        DrawText(play.text, (SCREEN_WIDTH - 28*5)/2, play.rec.y + (play.rec.height - font_size)/2, font_size, play.rec_color);
    }
    if (CheckCollisionPointRec(GetMousePosition(), sett.rec)) {
        DrawRectangleRounded(sett.rec, 0.5, 10, sett.text_color);
        DrawText(sett.text, (SCREEN_WIDTH - 73*5)/2, sett.rec.y + (sett.rec.height - font_size)/2, font_size, sett.rec_color);
    }
    if (CheckCollisionPointRec(GetMousePosition(), cred.rec)) {
        DrawRectangleRounded(cred.rec, 0.5, 10, cred.text_color);
        DrawText(cred.text, (SCREEN_WIDTH - 43*5)/2, cred.rec.y + (cred.rec.height - font_size)/2, font_size, cred.rec_color);
    }
    if (CheckCollisionPointRec(GetMousePosition(), quit.rec)) {
        DrawRectangleRounded(quit.rec, 0.5, 10, quit.text_color);
        DrawText(quit.text, (SCREEN_WIDTH - 19*5)/2, quit.rec.y + (quit.rec.height - font_size)/2, font_size, quit.rec_color);
    }
}

void UpdateMenu(void) {
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), play.rec)) {
        PlaySound(botaoSound); // Toca o som de botão
        currentScreen = HISTORY;
    }
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), sett.rec)) {
        PlaySound(botaoSound); // Toca o som de botão
        currentScreen = SETTINGS;
    }
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), cred.rec)) {
        PlaySound(botaoSound); // Toca o som de botão
        currentScreen = CREDITS;
    }
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), quit.rec)) {
        PlaySound(botaoSound); // Toca o som de botão
        currentScreen = QUIT;
    }
}
