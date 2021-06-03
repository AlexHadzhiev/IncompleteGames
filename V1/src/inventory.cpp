#include <iostream>
#include <ncurses.h>
#include <cstdlib>
#include <cstring>

char grid[11][21];

struct Cursor 
{
	char input;
	int x; int y;
	char picked_item[10];
	Cursor()
	{
		x = 1; y = 1;
		input = 0;
		for (int i = 0; i < 10; i++) picked_item[i] = ' ';
	}
};

struct Item
{
	int index;
	int x; int y;
	char name[10];
	char symbol;
	char description[100];
	Item()
	{
		index = 0;
		x = 0; y = 0;
		for (int i = 0; i < 10; i++) name[i] = ' ';
		for (int i = 0; i < 10; i++) description[i] = ' ';
	}
};

void inventory_render()
{
	for (int i = 1; i <= 11 ; i += 2)
	{
		for (int j = 1; j <= 21; j += 2)
		{
			grid[i][j] = ' ';
			grid[i-1][j-1] = '+';
			grid[i-1][j] = '-';
			grid[i][j-1] = '|';
			grid[i][0] = '|';
		}
	}
}

void inventory_display(struct Cursor* curs, struct Item* item)
{
	clear();
	for (int i = 0; i < 11; ++i)
	{
		for (int j = 0; j < 21; j++) 
		{
			if (i == curs->y && j == curs->x)
		 	{
			 	attron(COLOR_PAIR(1));
			 	attrset(COLOR_PAIR(1));
			 	printw("%c", grid[i][j]);
			}
			else
			{
			 	attron(COLOR_PAIR(2));
			 	attrset(COLOR_PAIR(2));
				printw("%c", grid[i][j]); 
			}
		} 
		printw("\n");
	}
	if (curs->x == item->x && curs->y == item->y)
	{
		printw("\nName: %s\n", item->name);
		printw("Descripton: %s", item->description);
	}
	refresh();
}

void show_item(struct Cursor* curs, struct Item* item)
{
	if (curs->x == item->x && curs->y == item->y)
	{
		strcpy(curs->picked_item, item->name);
	}
} 

void fill(struct Cursor* curs, struct Item* item)
{
	getstr(item->name);
	item->symbol = item->name[0];
	item->x = curs->x; item->y = curs->y;
	grid[item->y][item->x] = item->symbol;
	show_item(curs, item);
}

void curs_move(struct Cursor* curs, struct Item* item)
{
	curs->input = getch();
	switch(curs->input)
	{
		case 65: if (curs->y > 2) { curs->y -= 2; break; } break;
		case 66: if (curs->y < 8) { curs->y += 2; break; } break;
		case 68: if (curs->x > 2) { curs->x -= 2; break; } break;
		case 67: if (curs->x < 18) { curs->x += 2; break; } break;
		case 49: fill(curs, item);
	}
}

int main(int argc, char const *argv[])
{
	initscr();
 	start_color();
	noecho();
	cbreak();
	curs_set(0);

	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	init_pair(2, COLOR_WHITE, COLOR_BLACK);

	struct Cursor curs;
	struct Item** items = new Item*[10];
	for(int i = 0; i < 10; ++i) items[i] = new Item;

	inventory_render();
	inventory_display(&curs, items[0]);

	while(1)
	{
		for(int i = 0; i < 10; ++i)
		{	
			curs_move(&curs, items[i]);
			inventory_display(&curs, items[i]);
		}
	}

	getch();
	clear(); refresh();
	endwin();

	return 0;
}