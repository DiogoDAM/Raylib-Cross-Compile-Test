#include "raylib.h"

class Player
{
	public:
		Player(Vector2 pos, Vector2 vel);

		void update(float deltaTime);
		void draw();

	private:
		Vector2 m_pos;
		Vector2 m_vel;
		int m_width;
		int m_height;
		Color m_color;
};
