#include "RectF.h"

RectF::RectF(float leftIn, float rightIn, float topIn, float bottomIn)
	:
	left(leftIn),
	right(rightIn),
	top(topIn),
	bottom(bottomIn)
{
}

RectF::RectF(const Vec2 & topLeft, const Vec2 & bottomRight)
	:
	RectF( topLeft.x, bottomRight.x, topLeft.y, bottomRight.y)
{
}

RectF::RectF(const Vec2 & topLeft, float width, float height)
	:
	RectF(topLeft, topLeft+ Vec2(width, height))
{
}

bool RectF::IsOverLappingWidth(const RectF & other) const
{
	return right > other.left && left < other.right
		&& bottom > other.top && top < other.bottom;
}
