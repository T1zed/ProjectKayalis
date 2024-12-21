#include "raylib.h"
#include "player.h"

int main() {
    InitWindow(800, 600, "Platformer");


    Player player(Rectangle{ 400, 300, 50, 50 });
    player.Init(400, 300, 50, 50);  
    while (!WindowShouldClose()) {
        player.Update();
        BeginDrawing();
        ClearBackground(RAYWHITE);
        player.Draw();
        EndDrawing();
    }
    CloseWindow();

    return 0;
}

