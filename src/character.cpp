
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
  world_pos_last_frame_ = world_pos_;

  Vector2 direction{};
  if (IsKeyDown(KEY_A)) {
    direction.x -= 1;
  }
  if (IsKeyDown(KEY_D)) {
    direction.x += 1;
  }
  if (IsKeyDown(KEY_W)) {
    direction.y -= 1;
  }
  if (IsKeyDown(KEY_S)) {
    direction.y += 1;
  }
  if (Vector2Length(direction) != 0) {
    world_pos_ = Vector2Add(world_pos_,
                            Vector2Scale(Vector2Normalize(direction), speed_));

    right_left_ = direction.x > 0 ? 1 : -1;
    active_texture_ = &run_;
  } else {
    active_texture_ = &idle_;
  }

  // update animation
  running_time_ += delta_time;
  if (running_time_ >= update_time_) {
    running_time_ = 0;
    frame_ = (frame_ + 1) % max_frame_;
  }

  // draw character
  Rectangle source{width_ * frame_, 0, right_left_ * width_, height_};
  Rectangle dest{screen_pos_.x, screen_pos_.y, width_ * scale_,
                 height_ * scale_};
  DrawTexturePro(*active_texture_, source, dest, Vector2{0, 0}, 0.0f, WHITE);
}
