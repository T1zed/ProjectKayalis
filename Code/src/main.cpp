#include "game.h"

int main() {
    Game& game = Game::GetInstance(); 

    game.Init();  

    while (!WindowShouldClose()) {
        game.Update(); 
        game.Draw();  
    }

    game.Close(); 
    return 0;
}

