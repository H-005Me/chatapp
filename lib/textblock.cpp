#include "textblock.h"
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>

namespace h005
{

void SetCursorPos (const Coord<int32_t> coord)
{ printf("\033[%d;%dH", coord.x, coord.y); }

Coord<int32_t> GetCursorPos ()
{
	Coord<int32_t> coord;

	termios def; /// default
	tcgetattr(STDOUT_FILENO, &def);
	
	termios mod = def; /// modified
	cfmakeraw(&mod);
	
	tcsetattr(STDOUT_FILENO, TCSANOW, &mod); /// apply modified
	
	/// get cursor coords
	printf("\033[6n");   fflush(stdout); /// flush
	scanf("\033[%d;%dR", &coord.x, &coord.y);
	
	tcsetattr(STDOUT_FILENO, TCSANOW, &def); /// apply default

	return coord;
}

Textblock& operator << (Textblock& tb, const std::string& s)
{
	if (tb.cursorpos.x == -1) /// tb position hasn't been initialized
		return tb;
	
	Coord<int32_t> old_cursor = GetCursorPos(); /// get old cursor position
	SetCursorPos(tb.cursorpos); /// put cursor at tb
	
	for (int32_t i = 0; i < tb.msglen; i++) /// delete old tb message
		std::cout << ' ';
	
	SetCursorPos(tb.cursorpos); /// put cursor at tb (again)
	std::cout << s << std::flush;       /// output new message
	tb.msglen = s.size(); /// update tb.msglen
	
	SetCursorPos(old_cursor); /// put cursor where it was before
	
	return tb;
}

}

