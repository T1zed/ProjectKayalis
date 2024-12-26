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
    InitWalls();
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
void Game::InitWalls() {

    walls.push_back({ 800, 100,200,400 });

}

bool Game::CheckCollisionX(const Rectangle& rect1, const Rectangle& rect2) {
    return (rect1.x + rect1.width > rect2.x && rect1.x < rect2.x + rect2.width);
}

bool Game::CheckCollisionY(const Rectangle& rect1, const Rectangle& rect2) {
    return (rect1.y + rect1.height > rect2.y && rect1.y < rect2.y + rect2.height);
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

    bool isOnWallNow = false;

    for (const auto& wall : walls) {
        if (CheckCollisionY(redRectangle, wall)) {
            if (redRectangle.x + redRectangle.width > wall.x && redRectangle.x < wall.x + wall.width) {  
                isOnWallNow = true;
                player->OnWallCollision(wall);  
                break;
            }
        }
    }

    if (isOnWallNow) {
        if (!player->IsOnWall()) {  
            player->setOnWall(true);
        }
    }
    else {
        if (player->IsOnWall()) {
            player->setOnWall(false);
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

    for (const auto& walls : walls) {
        DrawRectangleRec(walls, PURPLE);
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

