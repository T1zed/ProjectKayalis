#include "game.h"

Game& Game::GetInstance() {
    static Game instance;
    return instance;
}

void Game::Init() {
    InitWindow(2000, 1000, "Platformer");
    SetTargetFPS(100);
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

    bool isOnGroundNow = player->IsOnGround();

    for (const auto& ground : grounds) {
        if (CheckCollisionRecs(player->getRectangle(), ground)) {
            isOnGroundNow = true;
            player->OnGroundCollision(ground);
        }
        else
        {
            isOnGroundNow = false;
        }
    }


    if (isOnGroundNow) {
        if (!player->IsOnGround()) {
            player->setOnGround(true);
        }
    }
    else {
        if (player->IsOnGround()) {
            player->setOnGround(false);
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

