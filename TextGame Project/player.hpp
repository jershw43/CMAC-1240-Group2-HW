#include <string>
#ifndef PLAYER_HPP
#define PLAYER_HPP

struct Player {
    std::string name;
    std::string className;
    int health;
    int attack;
    int defense;
    int level;
    int experience;
};

#endif // PLAYER_HPP