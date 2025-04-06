#include "raylib.h"
#include "game.h"

Rectangle rec = {(SCREEN_WIDTH - 400)/2, (SCREEN_HEIGHT - 80)/2, 400, 80};
Button name, play, sett, cred, quit;
Button config, sound, music, back;
Line sound_line, music_line, line = {(SCREEN_WIDTH)/2, (SCREEN_HEIGHT)/2, 300, RAYWHITE};
Rectangle sound_rec, music_rec;
int font_size = 50;
int soundPressed = 0;
int musicPressed = 0;

void SetMenu(void) {
    name.rec = (Rectangle) {rec.x - 30, rec.y - 240, rec.width, rec.height};
    play.rec = (Rectangle) {rec.x, rec.y -  40, rec.width, rec.height}; play.rec_color = RAYWHITE;
    sett.rec = (Rectangle) {rec.x, rec.y +  60, rec.width, rec.height}; sett.rec_color = RAYWHITE;
    cred.rec = (Rectangle) {rec.x, rec.y + 160, rec.width, rec.height}; cred.rec_color = RAYWHITE;
    quit.rec = (Rectangle) {rec.x, rec.y + 260, rec.width, rec.height}; quit.rec_color = RAYWHITE;

    strcpy(name.text, "CIn-Type");        name.text_color = RAYWHITE;
    strcpy(play.text, "Jogar");           play.text_color = BLACK;
    strcpy(sett.text, "Configurações");   sett.text_color = BLACK;
    strcpy(cred.text, "Créditos");        cred.text_color = BLACK;
    strcpy(quit.text, "Sair");            quit.text_color = BLACK;
}

void SetSettings(void) {
    config.rec = (Rectangle) {rec.x - 30, rec.y - 240, rec.width, rec.height};
    sound.rec  = (Rectangle) {rec.x, rec.y -  90, rec.width, rec.height};
    music.rec  = (Rectangle) {rec.x, rec.y +  60, rec.width, rec.height};
    back.rec   = (Rectangle) {(SCREEN_WIDTH - 33*5)/2, rec.y + 260, 33*5, 50};

    strcpy(config.text, "Configurações");  config.text_color = RAYWHITE;
    strcpy(sound.text, "Som");             sound.text_color = RAYWHITE;
    strcpy(music.text, "Música");          music.text_color = RAYWHITE;
    strcpy(back.text, "Voltar");           back.text_color = RAYWHITE;

    sound_line = (Line) {line.x - line.size/2, line.y -  40, line.size, line.color};
    music_line = (Line) {line.x - line.size/2, line.y + 110, line.size, line.color};
    sound_rec = (Rectangle) {line.x - 5, line.y -  40 - 10, 10, 20};
    music_rec = (Rectangle) {line.x - 5, line.y + 110 - 10, 10, 20};
}

void DrawMenu(void) {
    SetMenu();
    ClearBackground(BLACK);

    DrawRectangleRounded(play.rec, 0.5, 10, play.rec_color);
    DrawRectangleRounded(sett.rec, 0.5, 10, sett.rec_color);
    DrawRectangleRounded(cred.rec, 0.5, 10, cred.rec_color);
    DrawRectangleRounded(quit.rec, 0.5, 10, quit.rec_color);
    
    DrawText(name.text, (SCREEN_WIDTH - 564)/2, name.rec.y + (play.rec.height - 120)/2, 120, name.text_color);
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

void DrawSettings(void) {
    SetSettings();
    ClearBackground(BLACK);

    DrawText(config.text, (SCREEN_WIDTH - 146*5)/2, config.rec.y + (config.rec.height - 100)/2, 100, config.text_color);
    DrawText(sound.text,  (SCREEN_WIDTH - 18*5)/2, sound.rec.y + (sound.rec.height - font_size)/2, font_size, sound.text_color);
    DrawText(music.text,  (SCREEN_WIDTH - 33*5)/2, music.rec.y + (music.rec.height - font_size)/2, font_size, music.text_color);
    DrawText(back.text,   (SCREEN_WIDTH - 33*5)/2, back.rec.y  + (back.rec.height - font_size)/2, font_size, back.text_color);
    
    DrawLine(sound_line.x, sound_line.y, sound_line.x + sound_line.size, sound_line.y, sound_line.color);
    DrawLine(music_line.x, music_line.y, music_line.x + music_line.size, music_line.y, music_line.color);
    DrawRectangle(sound_rec.x, sound_rec.y, sound_rec.width, sound_rec.height, WHITE);
    DrawRectangle(music_rec.x, music_rec.y, music_rec.width, music_rec.height, WHITE);

    // back
    if (CheckCollisionPointRec(GetMousePosition(), back.rec)) {
        DrawText(back.text, (SCREEN_WIDTH - 33*5)/2, back.rec.y  + (back.rec.height - font_size)/2, font_size, GRAY);
    }
    // sound
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), sound_rec)) soundPressed = 1;
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) soundPressed = 0;

    if (soundPressed && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        DrawRectangle(sound_rec.x, sound_rec.y, sound_rec.width, sound_rec.height, BLACK);
        DrawLine(sound_line.x, sound_line.y, sound_line.x + sound_line.size, sound_line.y, sound_line.color);

        if (GetMouseX() < sound_line.x) {
            sound_rec.x = sound_line.x;
            DrawRectangle(sound_line.x, sound_rec.y, sound_rec.width, sound_rec.height, WHITE);
        } else
        if (GetMouseX() > sound_line.x + sound_line.size) {
            sound_rec.x = sound_line.x + sound_line.size;
            DrawRectangle(sound_line.x + sound_line.size, sound_rec.y, sound_rec.width, sound_rec.height, WHITE);
        } else {
            sound_rec.x = GetMouseX() - sound_rec.width/2;
            DrawRectangle(GetMouseX(), sound_rec.y, sound_rec.width, sound_rec.height, WHITE);
        }
    }
    // music
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), music_rec)) musicPressed = 1;
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) musicPressed = 0;

    if (musicPressed && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        DrawRectangle(music_rec.x, music_rec.y, music_rec.width, music_rec.height, BLACK);
        DrawLine(music_line.x, music_line.y, music_line.x + music_line.size, music_line.y, music_line.color);

        if (GetMouseX() < music_line.x) {
            music_rec.x = music_line.x;
            DrawRectangle(music_line.x, music_rec.y, music_rec.width, music_rec.height, WHITE);
        } else
        if (GetMouseX() > music_line.x + music_line.size) {
            music_rec.x = music_line.x + music_line.size;
            DrawRectangle(music_line.x + music_line.size, music_rec.y, music_rec.width, music_rec.height, WHITE);
        } else {
            music_rec.x = GetMouseX() - music_rec.width/2;
            DrawRectangle(GetMouseX(), music_rec.y, music_rec.width, music_rec.height, WHITE);
        }
    }
}

void DrawCredits(void) {
    ClearBackground(BLACK);
    DrawText("Créditos", SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 50, RAYWHITE);
    //DrawText("................................................................................................................................", 0, back.rec.y - 10, 50, RED); // DEBUG
    //DrawText("_____________________________________________________________________________________________", 0, back.rec.y - 15, 50, RED); // DEBUG
}

void UpdateMenu(void) {
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), play.rec)) currentScreen = GAMEPLAY;
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), sett.rec)) currentScreen = SETTINGS;
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), cred.rec)) currentScreen = CREDITS;
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), quit.rec)) currentScreen = QUIT;
}

void UpdateSettings(void) {
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), back.rec)) currentScreen = MENU;
}

void UpdateCredits(void) {
    if (IsKeyPressed(KEY_BACKSPACE)) {
        currentScreen = MENU;
    }
}
