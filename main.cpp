#include "raylib.h"

#include <cmath>
#include <ctime>

#include <vector>

#include "src/Player.h"


int const c_window_width = 800;
int const c_window_height = 600;
const char* const c_game_window_title = "Game Window for test Cross Compiler";

float random_float(int min, int max) { return (float) (min + (rand() % (max - min))); }

int main()
{

	srand(time(0));
	std::vector<Player> objs = {};

	for(int i=0; i<2000; i++)
	{
		objs.emplace_back(Player(Vector2{random_float(0.0, 800.0), random_float(0.0, 600.0)},
			Vector2{random_float(-200.0, 200.0), random_float(-200.0, 200.0)}));
	}

	InitWindow(c_window_width, c_window_height, c_game_window_title);
	SetTargetFPS(60);

	Texture2D texture = LoadTexture("content/textures/miia.png");
	Vector2 pos = {200, 0};
	float rotation = 0;
	float scale = 1;
	float value = 0;

	SetTargetFPS(60);

	while(!WindowShouldClose())
	{
		if(IsKeyPressed(KEY_ESCAPE)) CloseWindow();

		for(Player& p : objs)
		{
			p.update(GetFrameTime());
		}

		pos.x += cos(value * 0.1) * 20 ;
		value += 1;


		BeginDrawing();
		ClearBackground(WHITE);

			for(Player& p : objs)
			{
				p.draw();
			}

		EndDrawing();
	}

	return 0;
}

