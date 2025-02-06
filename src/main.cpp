#include "raylib.h"
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

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(BLACK);

    DrawTextureEx(map, {0, 0}, 0, 4.0f, WHITE);

    EndDrawing();
  }

  UnloadTexture(map);

  CloseWindow();
  return 0;
}
