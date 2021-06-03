#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <conio.h>
#include <ncurses.h>



int input;
int x, y, dir;

int map[10][10] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 4, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};


int main(int argc, char const *argv[])
{

	initscr();
	noecho();
	curs_set(0);	
	cbreak();
	refresh();

	// displaying map
	//////////////////////////////////////////////////////
	while(1)
	{
		for(int i = 0; i < 10; i++)
		{
			for(int j = 0; j < 10; j++)
			{
				if (map[i][j] == 1)
				{
					printw("#");
				}
				else if(map[i][j] == 0)
				{
					printw(" ");
				}
				else if (map[i][j] == 4)
				{
					printw("@");
				}
			}
			printw("\n");
		}
		////////////////////////////////////////////////////////

		printw("w-up, s-down, a-left, d-right: ");
		// scanf("%d\n", &input);
		input = getch();
		if (dir == 1)
		{
			x = 0;
			y = 1;
		}
		else if(dir == 2)
		{
			x = 0;
			y = -1;
		}
		else if(dir == 3)
		{
			x = 1;
			y = 0;
		}
		else if(dir == 4)
		{
			x = -1;
			y = 0;
		}

		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				if (map[i][j] == 4)
				{
					if (input == 119 && map[i-1][j] != 1)
					{
						map[i][j] = 0;
						map[i-1][j] = 4;
						dir = 1;
						clear();
						refresh();
					}
					else if (input == 115 && map[i+1][j] != 1)
					{
						map[i][j] = 0;
						map[i+1][j] = 4;
						dir = 2;
						clear();
						refresh();					}
					else if (input == 97 && map[i][j-1] != 1)
					{
						map[i][j] = 0;
						map[i][j-1] = 4;
						dir = 3;
						clear();
						refresh();
					}
					else if (input == 100 && map[i][j+1] != 1)
					{
						map[i][j] = 0;
						map[i][j+1] = 4;
						dir = 4;
						clear();
						refresh();
					}
				}
			}
		}
	}
	endwin();
	return 0;
}
