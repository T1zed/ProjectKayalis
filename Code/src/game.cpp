#include "game.h"

Game& Game::GetInstance() {
    static Game instance;
    return instance;
}

void Game::Init() {
    InitWindow(2000, 1000, "Platformer");
    InitPlayer(); 
}

void Game::InitPlayer() {
    player = new Player(Rectangle{ 400, 300, 250, 250 });  
    player->Init(400, 300);
}

void Game::Update() {
    if (player != nullptr) {
        player->Update();
    }
}

void Game::Draw() {
    BeginDrawing();
    ClearBackground(RAYWHITE);
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

