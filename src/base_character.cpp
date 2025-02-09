
#include "base_character.h"

Vector2 BaseCharacter::GetWorldPos() const { return world_pos_; }

void BaseCharacter::Tick(float delta_time) {

}

void BaseCharacter::undoMovement() { world_pos_ = world_pos_last_frame_; }

Rectangle BaseCharacter::GetCollisionRec() const {
  return Rectangle{screen_pos_.x, screen_pos_.y, width_ * scale_,
                   height_ * scale_};
}
