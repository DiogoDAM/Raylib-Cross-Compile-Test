#include "raylib.h"

#include <cmath>

int const c_window_width = 800;
int const c_window_height = 600;
const char* const c_game_window_title = "Game Window for test Cross Compiler";

int main()
{
	InitWindow(c_window_width, c_window_height, c_game_window_title);

	Texture2D texture = LoadTexture("content/textures/miia.png");
	Vector2 pos = {200, 0};
	float rotation = 0;
	float scale = 1;
	float value = 0;

	SetTargetFPS(60);

	while(!WindowShouldClose())
	{
		if(IsKeyPressed(KEY_ESCAPE)) CloseWindow();

		pos.x += cos(value * 0.1) * 20 ;
		value += 1;

		BeginDrawing();
		ClearBackground(WHITE);

			DrawTextureEx(texture, pos, rotation, scale, WHITE);

		EndDrawing();
	}

	return 0;
}

