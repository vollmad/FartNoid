#pragma once
#include "RectF.h"
#include "Colors.h"
#include "Graphics.h"
#include "Ball.h"
class Brick {
private:
	RectF rect;
	Color color;
	bool IsDestroyed = false;
	static constexpr float padding = 1.0f;
public:
	Brick() = default;
	Brick(const RectF& rect_in, Color color_in);
	void Draw(Graphics& gfx) const;
	bool CheckBallCollision(const Ball& ball) const;
	void ExeBallColission(Ball& ball);
	Vec2 GetCenter() const;
};