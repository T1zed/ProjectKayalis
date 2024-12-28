#include "game.h"
#include "map.h"
#include "entity.h"
Game& Game::GetInstance() {
    static Game instance;
    return instance;
}

Player* player = nullptr;
void Game::Init() {
    InitWindow(2000, 1000, "Platformer");
    SetTargetFPS(60);

    camera.target = { 0, 0 }; 
    camera.offset = { 1000 / 2.0f, 500 / 2.0f }; 
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    InitPlayer(); 
    InitGrounds();
    InitWalls();
    InitSpikes();
}
void Game::UpdateCameraToFollow(const Rectangle& entity) {
    Vector2 targetPosition = { entity.x  , entity.y -400  };
    if (IsKeyDown(KEY_D)) {
        targetPosition.x += 50;  

    }
    if (IsKeyDown(KEY_A)) {
        targetPosition.x -= 100;  

    }
    float smoothness = 0.1f;
    camera.target.x = camera.target.x + (targetPosition.x - camera.target.x) * smoothness;
    camera.target.y = camera.target.y + (targetPosition.y - camera.target.y) * smoothness;
}

void Game::InitPlayer() {
    player = new Player(Rectangle{ 400, 300, 300, 200 });
    player->Init(400, 300, 300, 200);
}
void Game::InitGrounds() {

    grounds.push_back({ 100, 800, 2000, 50 });  

    grounds.push_back({ 700, 900, 50, 50 });

    grounds.push_back({ 700, 450, 50, 50 });

    grounds.push_back({ 1100, 80,20,20 });

}
void Game::InitWalls() {

    walls.push_back({ 800, 100,20,400 });

    walls.push_back({ 1100, 100,20,400 });

}

void Game::InitSpikes() {

    spikes.push_back({ 1100, 750,50,50 });

}

bool Game::CheckCollisionX(const Rectangle& rect1, const Rectangle& rect2) {
    return (rect1.x + rect1.width > rect2.x && rect1.x < rect2.x + rect2.width);
}

bool Game::CheckCollisionY(const Rectangle& rect1, const Rectangle& rect2) {
    return (rect1.y + rect1.height > rect2.y && rect1.y < rect2.y + rect2.height);
}


void Game::Update() {
    if (player != nullptr) {
        player->Update();  
        UpdateCameraToFollow(player->getRectangle());
    }
   
}


void Game::Draw() {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    BeginMode2D(camera);
    for (const auto& ground : grounds) {
        DrawRectangleRec(ground, DARKGRAY);
    }

    for (const auto& spikes : spikes) {
        DrawRectangleRec(spikes, RED);
    }

    for (const auto& walls : walls) {
        DrawRectangleRec(walls, PURPLE);
    }


    if (player != nullptr) {
        player->Draw();
    

    EndMode2D();
    int barWidth = 800;
    int barHeight = 50;
    int barX = 200;
    int barY = 50;

    int barWidth2 = 10;
    int barHeight2 = 50;
    int barX2 = 200;
    int barY2 = 0;
    DrawRectangle(barX, barY, barWidth, barHeight, DARKGRAY);

    DrawRectangle(barX2, barY2, barWidth2, barHeight2, DARKGRAY);

    DrawRectangle(barX2, barY2, (int)(barWidth2 * player->GetLife()), barHeight2, GREEN);

    if (player->IsDashing()) {
        DrawRectangle(barX, barY, (int)(barWidth * player->GetStaminaProgress()), barHeight, BLUE);
    }
    else
    {
        DrawRectangle(barX, barY, (int)(barWidth * player->GetStaminaProgress()), barHeight, RED);
    }
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

