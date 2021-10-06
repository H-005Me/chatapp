#pragma once

namespace h005
{

template <typename T>
struct Coord
{
	T x, y;
	
	Coord () : x(0), y(0) {}
	Coord (const T px, const T py) : x(px), y(py) {}
	
	void set (const T px, const T py)
	{ x = px;   y = py; }
	
	bool operator == (const Coord<T>& c)
	{ return (x == c.x && y == c.y); }
	
	bool operator != (const Coord<T>& c)
	{ return (x != c.x || y != c.y); }
};

}
