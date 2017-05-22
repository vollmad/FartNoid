#pragma once

#include "Ball.h"
#include "Vec2.h"
#include "RectF.h"
#include "Colors.h"
#include "Graphics.h"
#include "Keyboard.h"
class Paddle
{
public:
	Paddle(const Vec2& pos_in, float halfWidth_in, float halfHeight_in);
	void Draw(Graphics& gfx) const;
	bool IsBallCollision(Ball& ball);
	void IsWallCollision(const RectF& walls);
	void Update(const Keyboard& kbd, float dt);
	RectF GetRect() const;
	void ResetCooldown();
private:
	static constexpr float wingWidth = 18.0f;
	Color wingColor = Colors::Red;
	Color color = Colors::White;
	float halfWidth;
	float halfHeight;
	float speed = 300.0f;
	Vec2 pos;
	bool isCooldown = false;
};