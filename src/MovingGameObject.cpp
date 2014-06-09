#include "MovingGameObject.hpp"

void MovingGameObject::setSpeed(float vx, float vy, float mod) {
    this->speed = new Vector2D(vx * mod, vy * mod);
}

Vector2D* MovingGameObject::getSpeed() {
    return this->speed;
}
