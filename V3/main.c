#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

int grid[11][21];

int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

struct cursor
{
    char input;
    int x; int y;
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

void inventory_display(struct cursor c)
{
    system("clear");
    for(int i = 0; i < 11; ++i)
    {
        for(int j = 0; j < 21; ++j)
        {
            if(c.y == i && c.x == j)
                printf("X");
            else
                printf("%c", grid[i][j]);
        }
        printf("\n");
    }
    printf("[x] = %i  [y] = %i", (c.x / 2) + 1, (c.y / 2) + 1);
}

void init_cursor(struct cursor* c, int x, int y)
{
    c->x = x;
    c->y = y;
    c->input = ' ';
}

void move_cursor(struct cursor* c)
{
    c->input = getch();
    switch(c->input)
    {
    case 'w': if (c->y > 2) { c->y -= 2; break; } break;
    case 'a': if (c->x > 2) { c->x -= 2; break; } break;
    case 's': if (c->y < 8) { c->y += 2; break; } break;
    case 'd': if (c->x < 18) { c->x += 2; break; } break;
    }
}

int main(int argc, char* argv[])
{
    struct cursor c;

    printf("Hello World!");

    inventory_render();
    init_cursor(&c, 1, 1);

    while(1)
    {
        move_cursor(&c);
        inventory_display(c);
    }
}
