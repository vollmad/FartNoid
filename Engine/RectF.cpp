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

RectF RectF::GetExpanded(float offset) const
{
	return RectF(left - offset, right + offset, top - offset, bottom + offset);
}

RectF RectF::FromCenter(const Vec2 & center, float halfWidth, float halfHeight)
{
	const Vec2 half(halfWidth, halfHeight);
	return RectF(center - half, center + half);
}

bool RectF::IsOverLappingWidth(const RectF & other) const
{
	return right > other.left && left < other.right
		&& bottom > other.top && top < other.bottom;
}

Vec2 RectF::GetCenter() const
{
	return Vec2((left + right) / 2.0f, (top + bottom) / 2.0f);
}
