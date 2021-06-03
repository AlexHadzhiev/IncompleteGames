#include <cstdlib>
#include <unistd.h>
#include <cstdio>
#include <ctime>
#include <climits>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <ncurses.h>

#include "../include/map.h"
#include "../include/player.h"
#include "../include/enemy.h"

int main()
{
	initscr();
	cbreak();
	noecho();
	curs_set(0);

	Grid grid(14, 14);
	grid.print();

	getch();
	clear(); refresh();
	getch();
	endwin();
}