#include "player.h"

Player::Player(const Rectangle& rectangle) : Entity(rectangle), velocity{ 0.0f, 0.0f } {
    IdleFrames[0] = LoadTexture("Assets/Sadao/idle_sadao_1.png");
    IdleFrames[1] = LoadTexture("Assets/Sadao/idle_sadao_2.png"); 
    IdleFrames[2] = LoadTexture("Assets/Sadao/idle_sadao_3.png");
    IdleFrames[3] = LoadTexture("Assets/Sadao/idle_sadao_2.png");
    IdleFrames[4] = LoadTexture("Assets/Sadao/idle_sadao_1.png");

    runframes[0]= LoadTexture("Assets/Warrior/Individual Sprite/Run/Warrior_Run_1.png");
    runframes[1] = LoadTexture("Assets/Warrior/Individual Sprite/Run/Warrior_Run_2.png");
    runframes[2] = LoadTexture("Assets/Warrior/Individual Sprite/Run/Warrior_Run_3.png");
    runframes[3] = LoadTexture("Assets/Warrior/Individual Sprite/Run/Warrior_Run_4.png");
    runframes[4] = LoadTexture("Assets/Warrior/Individual Sprite/Run/Warrior_Run_5.png");
    runframes[5] = LoadTexture("Assets/Warrior/Individual Sprite/Run/Warrior_Run_6.png");
    runframes[6] = LoadTexture("Assets/Warrior/Individual Sprite/Run/Warrior_Run_7.png");
    runframes[7] = LoadTexture("Assets/Warrior/Individual Sprite/Run/Warrior_Run_8.png");
    Right = IdleFrames[0];  
}


void Player::Init(float x, float y) {
    rectangle.x = x;
    rectangle.y = y;
}

void Player::Update() {

    if (IsKeyDown(KEY_D)) {
        rectangle.x += 0.2f;
        isMooving = true;
        isRunningR = true;
        isRunningL = false;
        lastDirection = RIGHT; 
        elapsedTime += GetFrameTime();
        if (elapsedTime >= frameDuration) {
            elapsedTime = 0.0f;
            currentRunFrame = (currentRunFrame + 1) % 7;  
        }
    }
    else if (IsKeyReleased(KEY_D)) {
        isRunningR = false;
        isMooving = false;
    }

    if (IsKeyDown(KEY_A)) {
        rectangle.x -= 0.2f;
        isMooving = true;
        isRunningL = true;
        isRunningR = false;
        lastDirection = LEFT;  

        elapsedTime += GetFrameTime();
        if (elapsedTime >= frameDuration) {
            elapsedTime = 0.0f;
            currentRunFrame = (currentRunFrame + 1) % 7;
        }
    }
    else if (IsKeyReleased(KEY_A)) {
        isRunningL = false;
        isMooving = false;
    }

    if (isMooving == false) {
        elapsedTime += GetFrameTime();
        if (elapsedTime >= frameDuration) {
            elapsedTime = 0.0f;
            currentIdleFrame = (currentIdleFrame + 1) % 5;
            Right = IdleFrames[currentIdleFrame];
        }
    }
}


void Player::Draw() {
    Rectangle sourceRec = { 0.0f, 0.0f, (float)Right.width, (float)Right.height };
    Vector2 origin = { 0.0f, 0.0f };
    Rectangle destRec = { rectangle.x, rectangle.y, rectangle.width, rectangle.height };

    if (isRunningR) {
        sourceRec.width = (float)runframes[currentRunFrame].width;
        DrawTexturePro(runframes[currentRunFrame], sourceRec, destRec, origin, 0.0f, WHITE);
    }
    else if (isRunningL) {
        sourceRec.width = -runframes[currentRunFrame].width;  
        DrawTexturePro(runframes[currentRunFrame], sourceRec, destRec, origin, 0.0f, WHITE);
    }
    else {
        if (lastDirection == LEFT) {
            sourceRec.width = -IdleFrames[currentIdleFrame].width;  
        }
        else {
            sourceRec.width = IdleFrames[currentIdleFrame].width;
        }
        DrawTexturePro(IdleFrames[currentIdleFrame], sourceRec, destRec, origin, 0.0f, WHITE);
    }
}



