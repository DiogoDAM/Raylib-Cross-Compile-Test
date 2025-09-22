#include "Player.h"


Player::Player(Vector2 pos, Vector2 vel)
{
	m_pos = pos;
	m_vel = vel;
	m_width = 10;
	m_height = 10;
	m_color = RED;
}

void Player::update(float deltaTime)
{
	// if(IsKeyDown(KEY_D)) m_pos.x += (m_vel * deltaTime);
	// else if(IsKeyDown(KEY_A)) m_pos.x -= (m_vel * deltaTime);
	//
	// if(IsKeyDown(KEY_S)) m_pos.y += (m_vel * deltaTime);
	// else if(IsKeyDown(KEY_W)) m_pos.y -= (m_vel * deltaTime);

	m_pos.x += (m_vel.x * deltaTime);
	m_pos.y += (m_vel.y * deltaTime);

	if(m_pos.x <= 0) { m_pos.x = 0; m_vel.x *= -1; }
	else if(m_pos.x + m_width >= 800) { m_pos.x = 800 - m_width; m_vel.x *= -1; }

	if(m_pos.y <=0) { m_pos.y = 0; m_vel.y *= -1; }
	else if(m_pos.y + m_height >= 600) { m_pos.y = 600 - m_height; m_vel.y *= -1; }
}

void Player::draw()
{
	DrawRectangle(m_pos.x, m_pos.y, m_width, m_height, m_color);
}
