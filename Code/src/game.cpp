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
    player = new Player(Rectangle{ 400, 300, 300, 200 });  
    player->Init(400, 300, 300 ,200);
}
void Game::InitGrounds() {

    grounds.push_back({ 100, 800, 2000, 50 });  

    grounds.push_back({ 700, 900, 50, 50 });

    grounds.push_back({ 700, 450, 50, 50 });

}

bool Game::CheckCollisionX(const Rectangle& rect1, const Rectangle& rect2) {
    return (rect1.x + rect1.width > rect2.x && rect1.x < rect2.x + rect2.width);
}


void Game::Update() {
    if (player == nullptr) {
        return;
    }

    player->Update();
    Rectangle redRectangle = { player->getRectangle().x, player->getRectangle().y + 20,
                               player->getRectangle().width - 150, player->getRectangle().height - 20 };
    bool isOnGroundNow = false; 
    for (const auto& ground : grounds) {
        {
            if (CheckCollisionRecs(redRectangle, ground)) {
                if (redRectangle.y + redRectangle.width <= ground.y) {
                    isOnGroundNow = true;
                    player->OnGroundCollision(ground);
                    break;
                }
            }
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

