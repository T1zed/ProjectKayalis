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
private:
    Game() = default; 
    ~Game() = default; 

    Player* player = nullptr; 
    std::vector<Rectangle> grounds;
    void InitPlayer();
    void InitGrounds();
};

#endif

