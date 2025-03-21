#include "raylib.h"
#include "game.h"
#include <string.h>
#include <stdio.h>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720


int main(void)
{

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Projeto FPI");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        GameUpdate();
        
        BeginDrawing();
            ClearBackground(BLACK);
            GameDraw();
        EndDrawing();
    }
    
    GameUnload();
    CloseWindow();

    return 0;
}
