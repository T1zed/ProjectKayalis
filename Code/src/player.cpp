#include "player.h"

Player::Player(const Rectangle& rectangle) : Entity(rectangle), velocity{ 0.0f, 0.0f } {
    Right = LoadTexture("Assets/Warrior/Individual Sprite/Dash/Warrior_Dash_2.png");
}

void Player::Init(float x, float y, float width, float height) {
    rectangle.x = x;
    rectangle.y = y;
    rectangle.width = width;
    rectangle.height = height;
}

void Player::Update() {

    if (IsKeyPressed(KEY_D)) {  
        isRunningR = true;    
    }
    else if (IsKeyReleased(KEY_D)) {
        isRunningR = false;    
    }

    if (IsKeyDown(KEY_D)) {
        rectangle.x += 0.2f;  
    }




    if (IsKeyPressed(KEY_A)) {  
        isRunningL = true;     
    }
    else if (IsKeyReleased(KEY_A)) {
        isRunningL = false;    
    }


    if (IsKeyDown(KEY_A)) {
        rectangle.x -= 0.2f;  
    }

    if (IsKeyDown(KEY_S)) rectangle.y += 0.2f;    
    if (IsKeyDown(KEY_W)) rectangle.y -= 0.2f;      


}

void Player::Draw() {

    Rectangle sourceRec = { 0.0f, 0.0f, (float)Right.width, (float)Right.height };  
    Vector2 origin = { 0.0f, 0.0f };  


    Rectangle destRec = { rectangle.x, rectangle.y, rectangle.width+100, rectangle.height+100 }; 

    if (isRunningR) {
        sourceRec.width = (float)Right.width;  
        DrawTexturePro(Right, sourceRec, destRec, origin, 0.0f, WHITE);
    }
    else if (isRunningL) {

        sourceRec.width = -sourceRec.width;  
        DrawTexturePro(Right, sourceRec, destRec, origin, 0.0f, WHITE); 
    }
}
