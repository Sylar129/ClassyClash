
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
  if (!IsAlive()) {
    return;
  }
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

  // draw weapon

  Vector2 origin{};
  Vector2 offset{};
  float rotation{};
  if (right_left_ > 0) {
    origin = {0.f, weapon_.height * scale_};
    offset = {35, 55};
    weapon_collition_rec_ = {screen_pos_.x + offset.x,
                             screen_pos_.y + offset.y - weapon_.height * scale_,
                             weapon_.width * scale_, weapon_.height * scale_};
    ;
    rotation = IsMouseButtonDown(MOUSE_LEFT_BUTTON) ? 35.0f : 0;
  } else {
    origin = {weapon_.width * scale_, weapon_.height * scale_};
    offset = {25, 55};
    weapon_collition_rec_ = {screen_pos_.x + offset.x - weapon_.width * scale_,
                             screen_pos_.y + offset.y - weapon_.height * scale_,
                             weapon_.width * scale_, weapon_.height * scale_};
    rotation = IsMouseButtonDown(MOUSE_LEFT_BUTTON) ? -35.0f : 0;
  }

  Rectangle source{0, 0, static_cast<float>(weapon_.width) * right_left_,
                   static_cast<float>(weapon_.height)};
  Rectangle dest{screen_pos_.x + offset.x, screen_pos_.y + offset.y,
                 weapon_.width * scale_, weapon_.height * scale_};
  DrawTexturePro(weapon_, source, dest, origin, rotation, WHITE);

  DrawRectangleLinesEx(weapon_collition_rec_, 2.0f, RED);
}
