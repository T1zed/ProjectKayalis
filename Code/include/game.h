#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#include "player.h"
#include "vector"
class Game {
public:
    static Game& GetInstance(); 
    Game(const Game&) = delete;
    void operator=(const Game&) = delete;

    void Init();
    void Update();
    void Draw();
    void Close();
    bool CheckCollisionX(const Rectangle& rect1, const Rectangle& rect2);
    bool CheckCollisionY(const Rectangle& rect1, const Rectangle& rect2);

    void UpdateCameraToFollow(const Rectangle& entity);
private:
    Game() = default; 
    ~Game() = default; 

    Camera2D camera;
    void InitPlayer();
    void InitGrounds();
    void InitWalls();
    void InitSpikes();
};

#endif

