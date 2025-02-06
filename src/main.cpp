#include "raylib.h"
#include "raymath.h"
#include "resource_dir.h"  // utility header for SearchAndSetResourceDir

int main() {
  // Tell the window to use vsync and work on high DPI displays
  SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

  constexpr int kScreenWidth = 384;
  constexpr int kScreenHeight = 384;
  InitWindow(kScreenWidth, kScreenHeight, "Hello Raylib");

  // Utility function from resource_dir.h to find the resources folder and set
  // it as the current working directory so we can load from it
  SearchAndSetResourceDir("resources");

  constexpr float kScale = 4.0f;

  Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
  constexpr float kSpeed = 4.0f;
  Vector2 map_pos{};

  Texture2D knight = LoadTexture("characters/knight_idle_spritesheet.png");
  Vector2 knight_pos{kScreenWidth / 2.0f - kScale * 0.5f * knight.width / 6.0f,
                     kScreenHeight / 2.0f - kScale * 0.5f * knight.height};

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(BLACK);

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
      map_pos = Vector2Subtract(
          map_pos, Vector2Scale(Vector2Normalize(direction), kSpeed));
    }

    DrawTextureEx(map, map_pos, 0, kScale, WHITE);

    Rectangle source{0, 0, static_cast<float>(knight.width / 6.0f),
                     static_cast<float>(knight.height)};
    Rectangle dest{knight_pos.x, knight_pos.y,
                   static_cast<float>(knight.width * kScale / 6.0f),
                   static_cast<float>(knight.height * kScale)};
    DrawTexturePro(knight, source, dest, Vector2{0, 0}, 0.0f, WHITE);

    EndDrawing();
  }

  UnloadTexture(knight);
  UnloadTexture(map);

  CloseWindow();
  return 0;
}
