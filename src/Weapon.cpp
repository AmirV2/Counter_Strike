
#include "Weapon.h"

Weapon::Weapon(const std::string input_name, const int input_price, const int input_damage, const int input_reward) 
    : name(input_name), price(input_price), damage(input_damage), reward(input_reward) {}

std::string Weapon::get_name() const {
    return name;
}

int Weapon::get_damage() const {
    return damage;
}

int Weapon::get_reward() const {
    return reward;
}

int Weapon::get_price() const {
    return price;
}