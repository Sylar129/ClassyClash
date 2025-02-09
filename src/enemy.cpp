
#include "enemy.h"

Enemy::Enemy(int window_width, int window_height) {
  idle_ = LoadTexture("characters/goblin_idle_spritesheet.png");
  run_ = LoadTexture("characters/goblin_run_spritesheet.png");
  active_texture_ = &idle_;
  width_ = idle_.width / 6.0f;
  height_ = idle_.height;
  world_pos_ = {0.0f, 0.0f};
  speed_ = 2.5f;
}

Enemy::~Enemy() {
  UnloadTexture(idle_);
  UnloadTexture(run_);
}

void Enemy::Tick(float delta_time) {
  velocity_ = Vector2Subtract(target_->GetScreenPos(), screen_pos_);

  screen_pos_ = Vector2Subtract(world_pos_, target_->GetWorldPos());

  BaseCharacter::Tick(delta_time);
}
