#include "entity.h"

enum Direction { 
    LEFT = -1,
    RIGHT = 1 };


class Player : public Entity {
public:
    Player(const Rectangle& rectangle);
    void Init(float x, float y);
    void Update();
    void Draw();

private:
    Texture2D Right;  
    Texture2D AttackFrames[12];
    Texture2D Attack2Frames[10];
    Texture2D IdleFrames[6];  
    Texture2D runframes[8];

    Vector2 velocity;
    Direction lastDirection = RIGHT;
    float elapsedTime = 0.0f; 

    int currentIdleFrame = 0;     
    int currentRunFrame = 0;
    int currentAtkFrame = 0;

    const float frameDuration = 0.1f;  
    bool isDashAttacking = false;
    bool isAttacking = false;
    bool isRunningR = false;
    bool isRunningL = false;
    bool isMooving = false;
};



