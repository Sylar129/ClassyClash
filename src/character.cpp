
#include "character.h"

Character::Character(int window_width, int window_height) {
  idle_ = LoadTexture("characters/knight_idle_spritesheet.png");
  run_ = LoadTexture("characters/knight_run_spritesheet.png");
  active_texture_ = &idle_;
  width_ = idle_.width / 6.0f;
  height_ = idle_.height;
  screen_pos_ = {window_width / 2.0f - scale_ * 0.5f * width_,
                 window_height / 2.0f - scale_ * 0.5f * height_};
}

Character::~Character() {
  UnloadTexture(idle_);
  UnloadTexture(run_);
}

void Character::Tick(float delta_time) {
  if (IsKeyDown(KEY_A)) {
    velocity_.x -= 1;
  }
  if (IsKeyDown(KEY_D)) {
    velocity_.x += 1;
  }
  if (IsKeyDown(KEY_W)) {
    velocity_.y -= 1;
  }
  if (IsKeyDown(KEY_S)) {
    velocity_.y += 1;
  }

  BaseCharacter::Tick(delta_time);
}
