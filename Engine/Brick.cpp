#include "Brick.h"
#include <assert.h>
void Brick::ExeBallColission(Ball & ball)
{
	assert(CheckBallCollision( ball ));
	
	const Vec2 ballPos = ball.GetPosition();
	if (std::signbit(ball.GetVelocity().x) == std::signbit((ballPos - GetCenter()).x))
	{
		ball.ReboundY();
	}
	if (ballPos.x >= rect.left && ballPos.x <= rect.right)
		ball.ReboundY();
	else
		ball.ReboundX();
	IsDestroyed = true;
}

Vec2 Brick::GetCenter() const
{
	return rect.GetCenter();
}

Brick::Brick(const RectF & rect_in, Color color_in)
	:
	rect (rect_in),
	color(color_in)
{
}

void Brick::Draw(Graphics & gfx) const
{
	if(!IsDestroyed)
		gfx.DrawRect(rect.GetExpanded(-padding), color);
}

bool Brick::CheckBallCollision(const Ball & ball) const
{
	return !IsDestroyed && rect.IsOverLappingWidth(ball.GetRect());
}
