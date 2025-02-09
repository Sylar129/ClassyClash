#pragma once

#include "base_character.h"
#include "raylib.h"
#include "raymath.h"

class Character : public BaseCharacter {
 public:
  Character(int window_width, int window_height);
  ~Character();
  void Tick(float delta_time) override;
  Vector2 GetScreenPos() const { return screen_pos_; }
  Rectangle GetWeaponCollisionRec() const { return weapon_collition_rec_; }

 private:
  Texture2D weapon_{LoadTexture("characters/weapon_sword.png")};
  Rectangle weapon_collition_rec_{};
};
