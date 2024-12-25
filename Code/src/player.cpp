#include "player.h"
#include "iostream"
Player::Player(const Rectangle& rectangle) : Entity(rectangle), velocity{ 0.0f, 0.0f } {
    IdleFrames[0] = LoadTexture("Assets/Warrior/Individual Sprite/Idle/Warrior_Idle_1.png");
    IdleFrames[1] = LoadTexture("Assets/Warrior/Individual Sprite/Idle/Warrior_Idle_2.png");
    IdleFrames[2] = LoadTexture("Assets/Warrior/Individual Sprite/Idle/Warrior_Idle_3.png");
    IdleFrames[3] = LoadTexture("Assets/Warrior/Individual Sprite/Idle/Warrior_Idle_4.png");
    IdleFrames[4] = LoadTexture("Assets/Warrior/Individual Sprite/Idle/Warrior_Idle_5.png");
    IdleFrames[5] = LoadTexture("Assets/Warrior/Individual Sprite/Idle/Warrior_Idle_6.png");

    runframes[0]= LoadTexture("Assets/Warrior/Individual Sprite/Run/Warrior_Run_1.png");
    runframes[1] = LoadTexture("Assets/Warrior/Individual Sprite/Run/Warrior_Run_2.png");
    runframes[2] = LoadTexture("Assets/Warrior/Individual Sprite/Run/Warrior_Run_3.png");
    runframes[3] = LoadTexture("Assets/Warrior/Individual Sprite/Run/Warrior_Run_4.png");
    runframes[4] = LoadTexture("Assets/Warrior/Individual Sprite/Run/Warrior_Run_5.png");
    runframes[5] = LoadTexture("Assets/Warrior/Individual Sprite/Run/Warrior_Run_6.png");
    runframes[6] = LoadTexture("Assets/Warrior/Individual Sprite/Run/Warrior_Run_7.png");
    runframes[7] = LoadTexture("Assets/Warrior/Individual Sprite/Run/Warrior_Run_8.png");

    AttackFrames[0] = LoadTexture("Assets/Warrior/Individual Sprite/Attack/Warrior_Attack_1.png");
    AttackFrames[1] = LoadTexture("Assets/Warrior/Individual Sprite/Attack/Warrior_Attack_2.png");
    AttackFrames[2] = LoadTexture("Assets/Warrior/Individual Sprite/Attack/Warrior_Attack_3.png");
    AttackFrames[3] = LoadTexture("Assets/Warrior/Individual Sprite/Attack/Warrior_Attack_4.png");
    AttackFrames[4] = LoadTexture("Assets/Warrior/Individual Sprite/Attack/Warrior_Attack_5.png");
    AttackFrames[5] = LoadTexture("Assets/Warrior/Individual Sprite/Attack/Warrior_Attack_6.png");
    AttackFrames[6] = LoadTexture("Assets/Warrior/Individual Sprite/Attack/Warrior_Attack_7.png");
    AttackFrames[7] = LoadTexture("Assets/Warrior/Individual Sprite/Attack/Warrior_Attack_8.png");
    AttackFrames[8] = LoadTexture("Assets/Warrior/Individual Sprite/Attack/Warrior_Attack_9.png");
    AttackFrames[9] = LoadTexture("Assets/Warrior/Individual Sprite/Attack/Warrior_Attack_10.png");
    AttackFrames[10] = LoadTexture("Assets/Warrior/Individual Sprite/Attack/Warrior_Attack_11.png");
    AttackFrames[11] = LoadTexture("Assets/Warrior/Individual Sprite/Attack/Warrior_Attack_12.png");

    Attack2Frames[0] = LoadTexture("Assets/Warrior/Individual Sprite/Dash-Attack_noDust/Warrior_Dash-Attack_1.png");
    Attack2Frames[1] = LoadTexture("Assets/Warrior/Individual Sprite/Dash-Attack_noDust/Warrior_Dash-Attack_2.png");
    Attack2Frames[2] = LoadTexture("Assets/Warrior/Individual Sprite/Dash-Attack_noDust/Warrior_Dash-Attack_3.png");
    Attack2Frames[3] = LoadTexture("Assets/Warrior/Individual Sprite/Dash-Attack_noDust/Warrior_Dash-Attack_4.png");
    Attack2Frames[4] = LoadTexture("Assets/Warrior/Individual Sprite/Dash-Attack_noDust/Warrior_Dash-Attack_5.png");
    Attack2Frames[5] = LoadTexture("Assets/Warrior/Individual Sprite/Dash-Attack_noDust/Warrior_Dash-Attack_6.png");
    Attack2Frames[6] = LoadTexture("Assets/Warrior/Individual Sprite/Dash-Attack_noDust/Warrior_Dash-Attack_7.png");
    Attack2Frames[7] = LoadTexture("Assets/Warrior/Individual Sprite/Dash-Attack_noDust/Warrior_Dash-Attack_8.png");
    Attack2Frames[8] = LoadTexture("Assets/Warrior/Individual Sprite/Dash-Attack_noDust/Warrior_Dash-Attack_9.png");
    Attack2Frames[9] = LoadTexture("Assets/Warrior/Individual Sprite/Dash-Attack_noDust/Warrior_Dash-Attack_10.png");

    jumpframes[0] = LoadTexture("Assets/Warrior/Individual Sprite/Jump/Warrior_Jump_1.png");
    jumpframes[1] = LoadTexture("Assets/Warrior/Individual Sprite/Jump/Warrior_Jump_2.png");
    jumpframes[2] = LoadTexture("Assets/Warrior/Individual Sprite/Jump/Warrior_Jump_3.png");
    jumpframes[3] = LoadTexture("Assets/Warrior/Individual Sprite/Jump/Warrior_Jump_2.png");
    jumpframes[4] = LoadTexture("Assets/Warrior/Individual Sprite/Jump/Warrior_Jump_3.png");
    jumpframes[5] = LoadTexture("Assets/Warrior/Individual Sprite/Jump/Warrior_Jump_2.png");
    jumpframes[6] = LoadTexture("Assets/Warrior/Individual Sprite/Jump/Warrior_Jump_3.png");
    jumpframes[7] = LoadTexture("Assets/Warrior/Individual Sprite/Jump/Warrior_Jump_2.png");
    jumpframes[8] = LoadTexture("Assets/Warrior/Individual Sprite/Jump/Warrior_Jump_3.png");
    Right = IdleFrames[0];  
}


void Player::Init(float x, float y) {
    rectangle.x = x;
    rectangle.y = y;
}

void Player::Update() {

    if (IsKeyPressed(KEY_W) && isOnGround) {
        verticalspeed = -10.0f;  
        isOnGround = false;      
        isJumping = true;        
        isMooving = true;        

        currentJumpFrame = 0;    
        elapsedTime = 0.0f;     
    }


    if (isJumping) {
        elapsedTime += GetFrameTime();  
        if (elapsedTime >= frameDuration) {
            elapsedTime = 0.0f;
            currentJumpFrame = (currentJumpFrame + 1) % 9;  
        }
    }

    if (isOnGround) {
        isJumping = false;  
        isMooving = false;  
        verticalspeed = 0.0f;  
        currentJumpFrame = 0;  
    }
    else if (!isJumping || !isOnGround) {
        verticalspeed += 0.2f;  
        rectangle.y += verticalspeed;  
        if (IsKeyDown(KEY_S)) {
            verticalspeed += 0.4f;
        }

    }

    if (isOnGround) {
        verticalspeed = 0.0f;
    }










    if (isAttacking || isDashAttacking) {
        elapsedTime += GetFrameTime();
        if (elapsedTime >= frameDuration) {
            elapsedTime = 0.0f;
            if (isDashAttacking) {
                currentAtkFrame = (currentAtkFrame + 1) % 10;  
                if (currentAtkFrame == 0) {
                    isDashAttacking = false;
                }
            }
            else {
                currentAtkFrame = (currentAtkFrame + 1) % 12;  
                if (currentAtkFrame == 0) {
                    isAttacking = false;
                }
            }
        }
    }
    else {
        
        if (IsKeyDown(KEY_D)) {
            rectangle.x += 2.0f;
            isMooving = true;
            isRunningR = true;
            isRunningL = false;
            lastDirection = RIGHT;
            elapsedTime += GetFrameTime();
            if (elapsedTime >= frameDuration) {
                elapsedTime = 0.0f;
                currentRunFrame = (currentRunFrame + 1) % 8;
            }
        }
        else if (IsKeyReleased(KEY_D)) {
            isRunningR = false;
            isMooving = false;
        }

        if (IsKeyDown(KEY_A)) {
            rectangle.x -= 2.0f;
            isMooving = true;
            isRunningL = true;
            isRunningR = false;
            lastDirection = LEFT;
            elapsedTime += GetFrameTime();
            if (elapsedTime >= frameDuration) {
                elapsedTime = 0.0f;
                currentRunFrame = (currentRunFrame + 1) % 8;
            }
        }
        else if (IsKeyReleased(KEY_A)) {
            isRunningL = false;
            isMooving = false;
        }




        if (!isMooving && !isJumping) {
            elapsedTime += GetFrameTime();
            if (elapsedTime >= frameDuration) {
                elapsedTime = 0.0f;
                currentIdleFrame = (currentIdleFrame + 1) % 6;
            }
        }




        if (isMooving && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            isDashAttacking = true;  
            currentAtkFrame = 0;
            elapsedTime = 0.0f;
            isMooving = false;  
            
        }
        else if (!isMooving && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            isAttacking = true;  
            currentAtkFrame = 0;
            elapsedTime = 0.0f;
        }
    }
}



void Player::Draw() {
    Rectangle sourceRec = { 0.0f, 0.0f, (float)Right.width, (float)Right.height };
    Vector2 origin = { 0.0f, 0.0f };
    Rectangle destRec = { rectangle.x, rectangle.y, rectangle.width, rectangle.height };
    DrawRectangleRec(rectangle, RED);
    if (isDashAttacking && !isJumping) {
        
        if (lastDirection == LEFT) {
            sourceRec.width = -Attack2Frames[currentAtkFrame].width;
        }
        else {
            sourceRec.width = (float)Attack2Frames[currentAtkFrame].width;
        }
        DrawTexturePro(Attack2Frames[currentAtkFrame], sourceRec, destRec, origin, 0.0f, WHITE);
    }
    else if (isAttacking && !isJumping) {
        
        if (lastDirection == LEFT) {
            sourceRec.width = -AttackFrames[currentAtkFrame].width;
        }
        else {
            sourceRec.width = (float)AttackFrames[currentAtkFrame].width;
        }
        DrawTexturePro(AttackFrames[currentAtkFrame], sourceRec, destRec, origin, 0.0f, WHITE);
    }
    else if (isRunningR && !isJumping) {
        
        sourceRec.width = (float)runframes[currentRunFrame].width;
        DrawTexturePro(runframes[currentRunFrame], sourceRec, destRec, origin, 0.0f, WHITE);
    }
    else if (isRunningL && !isJumping) {
        
        sourceRec.width = -runframes[currentRunFrame].width;
        DrawTexturePro(runframes[currentRunFrame], sourceRec, destRec, origin, 0.0f, WHITE);
    }
    else if(!isMooving && !isJumping){

        if (lastDirection == LEFT) {
            sourceRec.width = -IdleFrames[currentIdleFrame].width;
        }
        else {
            sourceRec.width = IdleFrames[currentIdleFrame].width;
        }
        DrawTexturePro(IdleFrames[currentIdleFrame], sourceRec, destRec, origin, 0.0f, WHITE);
    }
    else if (isJumping) {
        if (lastDirection == LEFT) {
            sourceRec.width = -jumpframes[currentJumpFrame].width;  
        }
        else {
            sourceRec.width = (float)jumpframes[currentJumpFrame].width;
        }
        DrawTexturePro(jumpframes[currentJumpFrame], sourceRec, destRec, origin, 0.0f, WHITE);
    }    
}

void Player::OnGroundCollision(const Rectangle& ground) {

    rectangle.y = ground.y - rectangle.height; 
    verticalspeed = 0.0f;  
    isOnGround = true;     
}

void Player::setOnGround(bool state) {
    isOnGround = state;  
}


