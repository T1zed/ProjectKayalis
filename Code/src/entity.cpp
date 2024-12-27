#include "entity.h"
#include "player.h"
#include "map.h"
Entity::Entity(const Rectangle& rectangle) : rectangle(rectangle) {

}

Rectangle Entity::getRectangle() const {
    return rectangle;
}

void Entity::setRectangle(const Rectangle& rectangle) {
    this->rectangle = rectangle;
}

void Entity::setOnGround(bool state) {
    isOnGround = state;
}

void Entity::Update() {

    Rectangle redRectangle = { getRectangle().x, getRectangle().y + 20,
                               getRectangle().width - 150, getRectangle().height - 20 };

    bool isOnGroundNow = false;
    for (const auto& ground : grounds) {
        {
            if (CheckCollisionRecs(redRectangle, ground)) {
                if (redRectangle.y + redRectangle.width <= ground.y) {
                    isOnGroundNow = true;
                    OnGroundCollision(ground);
                    break;
                }
            }
        }
    }

    if (isOnGroundNow) {
        if (!IsOnGround()) {
            setOnGround(true);
        }
    }
    else {
        if (IsOnGround()) {
            setOnGround(false);
        }
    }
}

void Entity::Draw() {
}

void Entity::OnGroundCollision(const Rectangle& ground) {

    rectangle.y = ground.y - rectangle.height;
    verticalspeed = 0.0f;
    isOnGround = true;
}

bool Entity::CheckCollisionX(const Rectangle& rect1, const Rectangle& rect2) {
    return (rect1.x + rect1.width > rect2.x && rect1.x < rect2.x + rect2.width);
}

bool Entity::CheckCollisionY(const Rectangle& rect1, const Rectangle& rect2) {
    return (rect1.y + rect1.height > rect2.y && rect1.y < rect2.y + rect2.height);
}

void Entity::Close() {
    
}