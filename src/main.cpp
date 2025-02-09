
#include "character.h"
#include "enemy.h"
#include "prop.h"
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
  Vector2 map_pos{};
  constexpr float kMapScale = 4.0f;

  Character knight{kScreenWidth, kScreenHeight};
  Enemy goblin{kScreenWidth, kScreenHeight};
  goblin.setTarget(&knight);
  Prop props[2] = {
      Prop{Vector2{400, 400}, LoadTexture("nature_tileset/Rock.png")},
      Prop{Vector2{600, 600}, LoadTexture("nature_tileset/Log.png")}};

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(BLACK);

    map_pos = Vector2Scale(knight.GetWorldPos(), -1);
    // draw map
    DrawTextureEx(map, map_pos, 0, kMapScale, WHITE);

    for (auto& prop : props) {
      prop.Render(knight.GetWorldPos());
    }

    knight.Tick(GetFrameTime());
    goblin.Tick(GetFrameTime());

    if (knight.GetWorldPos().x < 0.0f || knight.GetWorldPos().y < 0.0f ||
        knight.GetWorldPos().x + kScreenWidth > map.width * kMapScale ||
        knight.GetWorldPos().y + kScreenHeight > map.height * kMapScale) {
      knight.undoMovement();
    }

    for (const auto& prop : props) {
      if (CheckCollisionRecs(knight.GetCollisionRec(),
                             prop.GetCollisionRec(knight.GetWorldPos()))) {
        knight.undoMovement();
      }
    }

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
      bool killed = CheckCollisionRecs(knight.GetWeaponCollisionRec(),
                                       goblin.GetCollisionRec());
      goblin.setAlive(!killed);
    }

    EndDrawing();
  }

  UnloadTexture(map);

  CloseWindow();
  return 0;
}
