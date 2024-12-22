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
    Texture2D IdleFrames[5];  
    Texture2D runframes[7];
    Vector2 velocity;
    Direction lastDirection = RIGHT;
    float elapsedTime = 0.0f; 
    int currentIdleFrame = 0;     
    int currentRunFrame = 0;
    const float frameDuration = 0.4f;  
    bool isRunningR = false;
    bool isRunningL = false;
    bool isMooving = false;
};



