#ifndef ENTITY_H
#define ENTITY_H

#include "raylib.h"  

class Entity {
public:

    Entity(const Rectangle& rectangle);

    Rectangle getRectangle() const;
    void setRectangle(const Rectangle& rectangle);
    void Update();
    void Draw();
    void Close();
    void ResetOnGround() { isOnGround = false; }
    bool IsOnGround() const { return isOnGround; }
    void setOnGround(bool state);
    void OnGroundCollision(const Rectangle& ground);
    bool CheckCollisionX(const Rectangle& rect1, const Rectangle& rect2);
    bool CheckCollisionY(const Rectangle& rect1, const Rectangle& rect2);

    bool isOnGround = false;


protected:
    Rectangle rectangle;  
    float verticalspeed = 0.0f;
    float horizontalspeed = 0.0f;

};

#endif 
