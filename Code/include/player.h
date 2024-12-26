#include "entity.h"

enum Direction { 
    LEFT = -1,
    RIGHT = 1 };


class Player : public Entity {
public:
    Player(const Rectangle& rectangle);
    void Init(float x, float y, float w, float h);
    void Update();
    void Draw();
    void OnGroundCollision(const Rectangle& ground);
    void ResetOnGround() { isOnGround = false; }
    bool IsOnGround() const { return isOnGround; }
    void setOnGround(bool state);


    bool IsOnWall() const { return isOnWall; }
    void setOnWall(bool state);

    void OnWallCollision(const Rectangle& wall);
private:
    Texture2D Right;  
    Texture2D AttackFrames[12];
    Texture2D Attack2Frames[10];
    Texture2D IdleFrames[6];  
    Texture2D runframes[8];
    Texture2D jumpframes[9];

    Vector2 velocity;
    Direction lastDirection = RIGHT;
    float elapsedTime = 0.0f; 

    int currentIdleFrame = 0;     
    int currentRunFrame = 0;
    int currentAtkFrame = 0;
    int currentAtk2Frame = 0;
    int currentJumpFrame = 0;

    float barProgress = 1.0f;

    float verticalspeed= 0.0f;
    bool isOnGround = false;
    bool isJumping = false;
    bool isDashing = false;
    bool isOnWall = false; 
    const float frameDuration = 0.1f;  
    bool isDashAttacking = false;
    bool isAttacking = false;
    bool isRunningR = false;
    bool isRunningL = false;
    bool isMooving = false;
    bool CanDash = false;
    bool Playerdash = true;

};



