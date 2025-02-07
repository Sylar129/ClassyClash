#include "character.h"
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

  Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
  constexpr float kSpeed = 4.0f;
  Vector2 map_pos{};
  constexpr float kMapScale = 4.0f;

  Character knight;
  knight.setScreenPos(kScreenWidth, kScreenHeight);

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(BLACK);

    map_pos = Vector2Scale(knight.GetWorldPos(), -1);
    // draw map
    DrawTextureEx(map, map_pos, 0, kMapScale, WHITE);
    knight.tick(GetFrameTime());

    EndDrawing();
  }

  UnloadTexture(map);

  CloseWindow();
  return 0;
}
