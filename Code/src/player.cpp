#include "player.h"
#include "iostream"
#include "entity.h"
#include "map.h"
Player::Player(const Rectangle& rectangle) : Entity(rectangle), velocity{ 0.0f, 0.0f } {
    entity = new Entity(rectangle);
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

    Wallframes[0] = LoadTexture("Assets/Warrior/Individual Sprite/WallSlide/Warrior_WallSlide_1.png");
    Wallframes[1] = LoadTexture("Assets/Warrior/Individual Sprite/WallSlide/Warrior_WallSlide_2.png");
    Wallframes[2] = LoadTexture("Assets/Warrior/Individual Sprite/WallSlide/Warrior_WallSlide_3.png");
    Right = IdleFrames[0];  
}


void Player::Init(float x, float y,float w, float h) {
    rectangle.x = x;
    rectangle.y = y;
    rectangle.width = w;
    rectangle.height = h;
}

void Player::Update() {
    Entity::Update();

    if (staminaProgress >= 1.0f) {
        staminaProgress = 1.0f;  
        Playerdash = true;    
    }

    if (staminaProgress <= 0.0f) {
        staminaProgress = 0.0f;  
        Playerdash = false;  
    }

    

    if (IsKeyDown(KEY_W) && isOnGround && !isOnWall) {
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

    if (!isAttacking && !isDashAttacking && !isJumping)
        staminaProgress += 0.0008f;

    if (isAttacking || isDashAttacking) {
        elapsedTime += GetFrameTime();
        if (elapsedTime >= frameDuration) {
            elapsedTime = 0.0f;
            if (isDashAttacking) {
                currentAtk2Frame = (currentAtk2Frame + 1) % 10;  
                if (currentAtk2Frame == 0) {
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
        
        if (IsKeyDown(KEY_D) && !isRunningL) {
            rectangle.x += 2.0f;
            if (isOnGround  && Playerdash) {
                CanDash = true;
            }
            else
            {
                CanDash = false;
            }
            isMooving = true;
            isRunningR = true;
            isRunningL = false;
            lastDirection = RIGHT;
            elapsedTime += GetFrameTime();
            if (elapsedTime >= frameDuration) {
                elapsedTime = 0.0f;
                currentRunFrame = (currentRunFrame + 1) % 8;
            }
            if (IsKeyDown(KEY_KP_5)&& !isJumping && CanDash && Playerdash) {
                isDashing = true;
                rectangle.x += 8;
                staminaProgress -= 0.008f;
            }
        }
        else if (IsKeyReleased(KEY_D)) {
            isRunningR = false;
            isMooving = false;
        }

        if (IsKeyDown(KEY_A) && !isRunningR) {
            rectangle.x -= 2.0f;
            if (isOnGround && Playerdash) {
                CanDash = true;
            }
            else
            {
                CanDash = false;
            }
            isMooving = true;
            isRunningL = true;
            isRunningR = false;
            isDashing = false;
            lastDirection = LEFT;
            elapsedTime += GetFrameTime();
            if (elapsedTime >= frameDuration) {
                elapsedTime = 0.0f;
                currentRunFrame = (currentRunFrame + 1) % 8;
            }
            if (IsKeyDown(KEY_KP_5) && !isJumping && CanDash) {
                isDashing = true;
                rectangle.x -= 8;
                staminaProgress -= 0.008f;
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
        Attack();
        DashAttack();

        Rectangle redRectangle = { entity->getRectangle().x, entity->getRectangle().y + 20,
                                   entity->getRectangle().width - 150, entity->getRectangle().height - 20 };
        entity->setRectangle({ rectangle.x, rectangle.y, rectangle.width, rectangle.height });

        bool touchingspikes = false;

        for (const auto& spikes : spikes) {
            {
                if (CheckCollisionY(redRectangle, spikes)) {
                    if (redRectangle.x + redRectangle.width > spikes.x && redRectangle.x < spikes.x + spikes.width) {
                        touchingspikes = true;
                        OnspikesCollision(spikes);
                        break;
                    }
                }
            }
        }

        bool isOnWallNow = false;
        for (const auto& wall : walls) {
            if (CheckCollisionY(redRectangle, wall)) {
                if (redRectangle.x + redRectangle.width > wall.x && redRectangle.x < wall.x + wall.width) {
                    isOnWallNow = true;
                    OnWallCollision(wall);
                    break;
                }
            }
        }

        if (isOnWallNow) {
            if (IsOnWall()) {
                setOnWall(true);
            }
        }
        else {
            if (IsOnWall()) {
                setOnWall(false);
            }
        }
    }
}




void Player::Draw() {

    entity->Draw();

    Rectangle sourceRec = { 0.0f, 0.0f, (float)Right.width, (float)Right.height };
    Vector2 origin = { 50.0f, 0.0f };
    Rectangle destRec = { rectangle.x, rectangle.y, rectangle.width, rectangle.height };
    Rectangle redRectangle = { rectangle.x, rectangle.y+20, rectangle.width -150, rectangle.height-20 }; 
    int barWidth = 800;
    int barHeight = 50;
    int barX = 200;     
    int barY = 50;

    int barWidth2 = 10;
    int barHeight2 = 50;
    int barX2 = 200;
    int barY2 = 0;

    DrawRectangleRec(redRectangle, RED);
    

    if (isDashAttacking && !isJumping) {
        
        if (lastDirection == LEFT) {
            sourceRec.width = -Attack2Frames[currentAtk2Frame].width;
        }
        else {
            sourceRec.width = (float)Attack2Frames[currentAtk2Frame].width;
        }
        DrawTexturePro(Attack2Frames[currentAtk2Frame], sourceRec, destRec, origin, 0.0f, WHITE);
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
    else if (isRunningR && !isJumping && !isRunningL) {
        sourceRec.width = (float)runframes[currentRunFrame].width;
        DrawTexturePro(runframes[currentRunFrame], sourceRec, destRec, origin, 0.0f, WHITE);
    }
    
    else if (isRunningL && !isJumping && !isRunningR) {
        
        sourceRec.width = -runframes[currentRunFrame].width;
        DrawTexturePro(runframes[currentRunFrame], sourceRec, destRec, origin, 0.0f, WHITE);
    }
    else if(!isMooving && !isJumping && !isOnWall){

        if (lastDirection == LEFT) {
            sourceRec.width = -IdleFrames[currentIdleFrame].width;
        }
        else {
            sourceRec.width = IdleFrames[currentIdleFrame].width;
        }
        DrawTexturePro(IdleFrames[currentIdleFrame], sourceRec, destRec, origin, 0.0f, WHITE);
    }
    else if (isJumping && !isOnWall) {
        if (lastDirection == LEFT) {
            sourceRec.width = -jumpframes[currentJumpFrame].width;  
        }
        else {
            sourceRec.width = (float)jumpframes[currentJumpFrame].width;
        }
        DrawTexturePro(jumpframes[currentJumpFrame], sourceRec, destRec, origin, 0.0f, WHITE);
    }    

    else if (isOnWall) {

        if (lastDirection == LEFT) {
            sourceRec.width = -Wallframes[currentWallFrame].width;
        }
        else {
            sourceRec.width = Wallframes[currentWallFrame].width;
        }
        DrawTexturePro(Wallframes[currentWallFrame], sourceRec, destRec, origin, 0.0f, WHITE);
    }

    DrawRectangle(barX, barY, barWidth, barHeight, DARKGRAY);

    DrawRectangle(barX2, barY2, barWidth2, barHeight2, DARKGRAY);

    DrawRectangle(barX2, barY2, (int)(barWidth2 * PlayerLife), barHeight2, GREEN);

    if (Playerdash) {
        DrawRectangle(barX, barY, (int)(barWidth * staminaProgress), barHeight, BLUE);
    }
    else
    {
        DrawRectangle(barX, barY, (int)(barWidth * staminaProgress), barHeight, RED);
    }
}



void Player::setOnWall(bool state) {
    isOnWall = state;
}


void Player::DashAttack() {
    if (isMooving && IsKeyPressed(KEY_KP_4) && !isJumping) {
        isDashAttacking = true;
        currentAtkFrame = 0;
        elapsedTime = 0.0f;
        isMooving = false;

    }
}

void Player::Attack() {
    if (!isMooving && IsKeyPressed(KEY_KP_4) && !isJumping) {
        isAttacking = true;
        currentAtkFrame = 0;
        elapsedTime = 0.0f;
    }

}
void Player::OnWallCollision(const Rectangle& wall) {


    verticalspeed = 0.0f;

    float overlapLeft = (rectangle.x + rectangle.width) - wall.x;
    float overlapRight = (wall.x + wall.width) - rectangle.x;


    if (overlapLeft > 0 && rectangle.x < wall.x) {

        rectangle.x = wall.x - rectangle.width / 2;
        if (IsKeyPressed(KEY_W) && Playerdash) {
            rectangle.y -= 150.0f;
            rectangle.x -= 50.0f;
            staminaProgress -= 0.2f;
        }

    }

    else if (overlapRight > 0 && rectangle.x > wall.x) {

        rectangle.x = wall.x + wall.width;
        if (IsKeyPressed(KEY_W) && Playerdash) {
            rectangle.y -= 150.f;
            rectangle.x += 50.0f;
            staminaProgress -= 0.2f;
        }
    }
    isOnWall = true;
}

void Player::OnspikesCollision(const Rectangle& ground) {
    isOnSpike = true;
    PlayerLife -= 0.1f;
}