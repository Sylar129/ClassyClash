#pragma once

#include "base_character.h"

class Enemy : public BaseCharacter {
 public:
  Enemy(int window_width, int window_height);
  ~Enemy();
  virtual void Tick(float delta_time) override;
};
