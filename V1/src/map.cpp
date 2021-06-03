#include <ncurses.h>

#include "../include/map.h"
#include "../include/player.h"
#include "../include/enemy.h"

Grid::Grid(int x, int y, int spikes_x, int spikes_y): size_x(x), size_y(y)
{
    this->field = new unsigned char*[x];
    for(int i = 0; i < x; ++i)
    {
        this->field[i] = new unsigned char[y];
        for(int j = 0; j < y; ++j)
        {
            field[i][j] = '+';
        }
    }
}

void Grid::print()
{
    for(int i = 0; i < this->size_x; ++i)
    {
        printw("[");
        for(int j = 0; j < this->size_y; ++j)
        {
            printw("%c", this->field[i][j]);
            if(j != (this->size_y - 1)) printw(" ");
        }
        printw("]");
        printw("\n");
    }
}