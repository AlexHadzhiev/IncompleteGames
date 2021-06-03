#ifndef MAP__H
#define MAP__H

struct Grid
{
    Grid(int x, int y, int spikes_x, int spikes_y);
    Grid(int x, int y);
    Grid();

    void print();

    unsigned char** field;
    int size_x; int size_y;
};

#endif