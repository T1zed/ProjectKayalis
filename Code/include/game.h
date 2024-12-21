#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#include "player.h"

class Game {
public:
    static Game& GetInstance(); 
    Game(const Game&) = delete;
    void operator=(const Game&) = delete;

    void Init();
    void Update();
    void Draw();
    void Close();

private:
    Game() = default; 
    ~Game() = default; 

    Player* player = nullptr; 

    void InitPlayer();
};

#endif

