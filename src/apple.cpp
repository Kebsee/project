#include "apple.hpp"

Apple::Apple() {
  Vector2f startingPosition(400, 300);
  sprite.setSize(Vector2f(100, 100));
  sprite.setFillColor(Color::Red);
  sprite.setPosition(startingPosition);
}

void Apple::setPosition(Vector2f newPosition) {
  sprite.setPosition(newPosition);
}

RectangleShape Apple::getSprite() {
  return sprite;
}
