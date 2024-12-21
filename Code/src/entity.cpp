#include "entity.h"

Entity::Entity(const Rectangle& rectangle) : rectangle(rectangle) {

}

Rectangle Entity::getRectangle() const {
    return rectangle;
}

void Entity::setRectangle(const Rectangle& rectangle) {
    this->rectangle = rectangle;
}
