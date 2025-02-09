#pragma once

#include "base_character.h"
#include "raylib.h"
#include "raymath.h"

class Character : public BaseCharacter {
 public:
  Character(int window_width, int window_height);
  ~Character();
  void Tick(float delta_time) override;

 private:
};
