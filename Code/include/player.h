#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include "raylib.h"

class Player : public Entity {
public:
    Player(const Rectangle& rectangle);

    void Init(float x, float y, float width, float height);
    void Update();
    void Draw();

private:
    Vector2 velocity;  
    Texture2D Right;  
    bool isRunningR=false; 
    bool isRunningL = false;
};

#endif  


