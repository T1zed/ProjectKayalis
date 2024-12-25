#include "game.h"

Game& Game::GetInstance() {
    static Game instance;
    return instance;
}

void Game::Init() {
    InitWindow(2000, 1000, "Platformer");
    InitPlayer(); 
    InitGrounds();
}

void Game::InitPlayer() {
    player = new Player(Rectangle{ 400, 300, 200, 200 });  
    player->Init(400, 300);
}
void Game::InitGrounds() {

    grounds.push_back({ 100, 800, 500, 50 });  

}
void Game::Update() {
    if (player == nullptr) {
        return;
    }

    player->Update();

    for (const auto& ground : grounds) {
        if (CheckCollisionRecs(player->getRectangle(), ground)) {

            player->OnGroundCollision(ground);
            
        }
    }
}

void Game::Draw() {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    for (const auto& ground : grounds) {
        DrawRectangleRec(ground, DARKGRAY); 
    }
    if (player != nullptr) {
        player->Draw(); 
    }
    EndDrawing();
}

void Game::Close() {
    if (player != nullptr) {
        delete player;  
        player = nullptr;
    }
    CloseWindow(); 
}

