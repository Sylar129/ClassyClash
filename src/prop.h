#include "raylib.h"

class Prop{
  public:
   Prop(const Vector2& pos, const Texture2D& tex);
  void Render(const Vector2& knight_pos);
  Rectangle GetCollisionRec(const Vector2& knight_pos) const;

 private:
  Texture2D texture_{};
  Vector2 world_pos_{};
  float scale_{4};
};
