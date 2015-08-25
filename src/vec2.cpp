#include <gui.h>

Vec2::Vec2() {}
Vec2::Vec2(int x, int y) : x(x), y(y) {}

Vec2 & Vec2::operator+=(const Vec2 &other)
{
	x += other.x;
	y += other.y;
	return *this;
}

const Vec2 Vec2::operator+(const Vec2 &other)
{
	return Vec2(*this) += other;
}
