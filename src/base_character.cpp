
#include "base_character.h"

#include "raymath.h"

Vector2 BaseCharacter::GetWorldPos() const { return world_pos_; }

void BaseCharacter::Tick(float delta_time) {
  world_pos_last_frame_ = world_pos_;
  // update animation
  running_time_ += delta_time;
  if (running_time_ >= update_time_) {
    running_time_ = 0;
    frame_ = (frame_ + 1) % max_frame_;
  }

  if (Vector2Length(velocity_) != 0) {
    world_pos_ = Vector2Add(world_pos_,
                            Vector2Scale(Vector2Normalize(velocity_), speed_));

    right_left_ = velocity_.x > 0 ? 1 : -1;
    active_texture_ = &run_;
  } else {
    active_texture_ = &idle_;
  }
  velocity_ = {};

  // draw character
  Rectangle source{width_ * frame_, 0, right_left_ * width_, height_};
  Rectangle dest{screen_pos_.x, screen_pos_.y, width_ * scale_,
                 height_ * scale_};
  DrawTexturePro(*active_texture_, source, dest, Vector2{0, 0}, 0.0f, WHITE);
}

void BaseCharacter::undoMovement() { world_pos_ = world_pos_last_frame_; }

Rectangle BaseCharacter::GetCollisionRec() const {
  return Rectangle{screen_pos_.x, screen_pos_.y, width_ * scale_,
                   height_ * scale_};
}
