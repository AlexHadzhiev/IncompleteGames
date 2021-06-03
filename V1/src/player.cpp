#include "../include/map.h"
#include "../include/player.h"
#include "../include/enemy.h"

Player::Player(int hp, int x, int y): HP(hp), x(x), y(y), x2(0), y2(0) { }
Player::Player(): HP(1), x(0), y(0), x2(0), y2(0) { }

void Player::move(Grid* grid, char direcion)
{
    switch(direcion)
    {
        case 66: this->x = this->x2 - 1; this->y = this->y2; if(this->x2 == 0) break; break;
        case 65: this->x = this->x2 + 1; this->y = this->y2; if(this->x2 == (grid->size_x - 1)) break; break;
        case 68: this->x = this->x2; this->y = this->y2 - 1; if(this->y2 == 0) break; break;
        case 67: this->x = this->x2; this->y = this->y2 + 1; if(this->y2 == (grid->size_y - 1)) break; break;
    }
}