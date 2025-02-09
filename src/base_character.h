#pragma once

#include "raylib.h"

class BaseCharacter {
 public:
  virtual ~BaseCharacter() = default;
  Vector2 GetWorldPos() const;
  virtual void Tick(float delta_time);
  void undoMovement();
  Rectangle GetCollisionRec() const;

 protected:
  Texture2D* active_texture_;
  Texture2D idle_;
  Texture2D run_;
  Vector2 screen_pos_{};
  Vector2 world_pos_{};
  // 1: facing right, -1 : facing left
  float right_left_{1};
  // animation
  float running_time_{};
  int frame_{};
  int max_frame_{6};
  float update_time_{1.0f / 12.0f};
  float speed_{4.0f};
  float width_;
  float height_;
  Vector2 world_pos_last_frame_{};
  float scale_{4.0f};
  Vector2 velocity_{};
};
