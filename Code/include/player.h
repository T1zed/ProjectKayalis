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
    Entity* entity = nullptr;
    float GetStaminaProgress() const { return staminaProgress; }
    float GetLife() const { return PlayerLife; }
    bool IsOnWall() const { return isOnWall; }
    void setOnWall(bool state);
    bool IsDashing() const { return Playerdash; }
    void OnWallCollision(const Rectangle& wall);
    void OnspikesCollision(const Rectangle& spikes);
    void DashAttack();
    void Attack();
private:
    Texture2D Right;  
    Texture2D AttackFrames[12];
    Texture2D Attack2Frames[10];
    Texture2D IdleFrames[6];  
    Texture2D runframes[8];
    Texture2D jumpframes[9];
    Texture2D Wallframes[3];

    Vector2 velocity;
    Direction lastDirection = RIGHT;
    float elapsedTime = 0.0f; 

    int currentIdleFrame = 0;     
    int currentRunFrame = 0;
    int currentAtkFrame = 0;
    int currentAtk2Frame = 0;
    int currentJumpFrame = 0;
    int currentWallFrame = 0;


    float staminaProgress = 1.0f;
    float PlayerLife = 100.0f;
    
    bool isJumping = false;
    bool isDashing = false;
    bool isOnWall = false; 
    const float frameDuration = 0.1f;  
    bool isDashAttacking = false;
    bool isAttacking = false;
    bool isRunningR = false;
    bool isRunningL = false;
    bool isMooving = false;
    bool isOnSpike = false;
    bool CanDash = false;
    bool Playerdash = true;
    float DashSpeed = 0.0f;
    float dashTime = 0.0f;
    float dashDuration = 0.3f;
    bool walljump = false;

    bool isWallJumping = false;
    float wallJumpDuration = 0.0f;
    float wallJumpTimer = 0.0f;
    float wallJumpSpeedX = 0.0f;
    float wallJumpSpeedY = 0.0f;
};



