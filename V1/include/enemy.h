#ifndef ENEMY__H
#define ENEMY__H

struct Grid;

struct Enemy
{
    Enemy(int hp, int x, int y);
    Enemy();

    void move(Grid* grid);

    int x; int y;
    int x2; int y2;
    int HP;
};

#endif