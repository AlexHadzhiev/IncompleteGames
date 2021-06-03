#ifndef PLAYER__H
#define PLAYER__H

struct Grid;

struct Player
{
    Player(int hp, int x, int y);
    Player();

    void move(Grid* grid, char direction);

    int x; int y;
    int x2; int y2;
    int HP;
};

#endif