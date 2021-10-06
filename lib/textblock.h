#pragma once
#include <cstdint>
#include <ostream>
#include <string>
#include "coord.h"

namespace h005
{

void SetCursorPos (const Coord<int32_t>); /// {row, col}
Coord<int32_t> GetCursorPos ();           /// {row, col}

class Textblock
{
private:
	Coord<int32_t> cursorpos;
	int32_t msglen;

public:
	Textblock () : cursorpos(-1, -1), msglen(0) {}
	Textblock (const Coord<int32_t> c) : cursorpos(c), msglen(0) {}
	
	friend Textblock& operator << (Textblock&, const std::string&); /// only std::string for now
};

}
