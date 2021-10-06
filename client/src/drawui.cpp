#include "../inc/drawui.h"
#include <iostream>
#include <string>
#include "../../lib/textblock.h"

static const int RECEIVED_ROW = 0; /// received msgs will be written from this row
static const int WRITING_ROW = 40; /// current msg will be written from this row
static const int MAX_LENGTH = 211; /// length of maximized terminal
static const int MAX_HEIGHT = 52;  /// height of maximized terminal

void drawUi ()
{

    h005::Textblock writing(h005::Coord<int>(WRITING_ROW+1, 0));

    h005::SetCursorPos(h005::Coord<int>(WRITING_ROW, 0));
    for (int i = 0; i < MAX_LENGTH; i++)
        std::cout << 'X';
    std::cout << std::flush;
}

void writeReceived (const std::string& msg)
{
    static int currentRow = RECEIVED_ROW; /// row that the message should be written on

    h005::Coord<int> oldCursor = h005::GetCursorPos();   /// get old cursor pos
    h005::SetCursorPos(h005::Coord<int>(currentRow, 0)); /// move to new pos
    std::cout << msg << std::endl;
    h005::SetCursorPos(oldCursor); /// returns to old pos

    if (currentRow < WRITING_ROW-1) /// there's space for another msg (1 line msg rn)
        currentRow++;
}