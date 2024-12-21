#ifndef ENTITY_H
#define ENTITY_H

#include "raylib.h"  

class Entity {
public:

    Entity(const Rectangle& rectangle);


    Rectangle getRectangle() const;
    void setRectangle(const Rectangle& rectangle);



protected:
    Rectangle rectangle;  
};

#endif 
