
#include <iostream>
#include "Game_Manager.h"

Game_Manager::Game_Manager() :
    current_round(0), current_time(Timer(0, 0, 0)) {

    std::vector<Pistol> legal_pistols_terrorist;
    legal_pistols_terrorist.push_back(Pistol("Revolver", 600, 51 ,150));
    legal_pistols_terrorist.push_back(Pistol("Glock-18", 300, 11 ,200));

    std::vector<Heavy_Gun> legal_heavies_terrorist;
    legal_heavies_terrorist.push_back(Heavy_Gun("AK", 2700, 31 ,100));
    legal_heavies_terrorist.push_back(Heavy_Gun("AWP", 4300, 110 ,50));

    terrorist = new Team(legal_pistols_terrorist, legal_heavies_terrorist);

    std::vector<Pistol> legal_pistols_counter_terrorist;
    legal_pistols_counter_terrorist.push_back(Pistol("Desert-Eagle", 600, 53 ,175));
    legal_pistols_counter_terrorist.push_back(Pistol("UPS-S", 300, 13 ,225));

    std::vector<Heavy_Gun> legal_heavies_counter_terrorist;
    legal_heavies_counter_terrorist.push_back(Heavy_Gun("M4A1", 2700, 29 ,100));
    legal_heavies_counter_terrorist.push_back(Heavy_Gun("AWP", 4300, 110 ,50));

    counter_terrorist = new Team(legal_pistols_counter_terrorist, legal_heavies_counter_terrorist);
    
}

void Game_Manager::add_user(const std::string username, const std::string team, const std::string time) {

    Player player(username, current_round, current_time);
    
    try {
        if (team == "Terrorist") {
            terrorist->add_player(player);
        }
        else {
            counter_terrorist->add_player(player);
        }
        std::cout << "this user added to " << team << std::endl;
    }
    catch (Duplicate_UserName_Exception e) {
        std::cout << e << std::endl;
    }
    catch (Full_Team_Exception e) {
        std::cout << e << std::endl;
    }

}

void Game_Manager::get_money(const std::string username, const std::string time) {}

void Game_Manager::get_health(const std::string username, const std::string time) {}

void Game_Manager::tap(const std::string attacker, const std::string atatcked,
                const std::string weapon_type, const std::string time) {}

void Game_Manager::buy(const std::string username, const std::string weapon_name, const std::string time) {}

void Game_Manager::score_board(const std::string time) {}

void Game_Manager::start_new_round() {}

std::string Game_Manager::get_winner() {}

int Game_Manager::get_current_round() {
    return current_round;
}

void Game_Manager::update_current_time(std::string time) {}