#include "prop.h"
#include "raymath.h"

Prop::Prop(const Vector2& pos, const Texture2D& tex)
    : world_pos_{pos}, texture_{tex} {}

void Prop::Render(const Vector2& knight_pos) {
  Vector2 screen_pos = Vector2Subtract(world_pos_, knight_pos);
  DrawTextureEx(texture_, screen_pos, 0, scale_, WHITE);
}
