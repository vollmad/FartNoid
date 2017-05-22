#pragma once

#include "Graphics.h"

class SpriteCodex
{
public:
	static void DrawBall( const Vec2& center, Graphics& gfx );
	void DrawTitle(const Vec2 & center, Graphics & gfx);
	void DrawGameOver(const Vec2 & center, Graphics & gfx);
	void DrawReady(const Vec2 & center, Graphics & gfx);
	void DrawPoo(const Vec2 & center, Graphics & gfx);
};