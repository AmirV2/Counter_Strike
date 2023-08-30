
#include <string>
#include "PlayerStatistics.h"
#include "WeaponBundle.h"
#include "AllExceptions.h"
#include "Timer.h"

#ifndef PLAYER_H
#define PLAYER_H

/**
 * @brief Store information about the player
 * 
 *   Manages the actions which can be done by a player and like buying weapons,
 * attacking and getting attacked and stores the specifications of statistic information
 * about the player.
 * 
 */
class Player {

public:

    /**
     * @brief Construct a new Player object
     * 
     * @param input_username player's username
     * @param join_time the time when the player has joined the game
     */
    Player(const std::string input_username = "no name", const int input_join_round = 0,
            Timer input_join_time = Timer(0, 0, 0));

    /**
     * @brief Buy a new pistol type waepon for the player
     * 
     *   All the problems that might happen are checked and proper
     * exceptions will be thrown should there be any kind of hazard.
     * 
     * @param pistol the pistol object which the player want's to buy
     */
    void buy_pistol(Pistol& pistol); 

    /**
     * @brief Buy a new heavy type waepon for the player
     * 
     *   All the problems that might happen are checked and proper
     * exceptions will be thrown should there be any kind of hazard.
     * 
     * @param heavy_gun the heavy gun object which the player want's to buy
     */
    void buy_heavy_gun(HeavyGun& heavy_gun);

    /**
     * @brief Check if the player is alive and has time to buy a gun
     * 
     * @param current_time current time of this round
     * @return true the player can buy gun
     * @return false the player can't buy gun
     */
    void can_buy(const Timer& current_time);

    /**
     * @brief Manage the attacking action for this player
     * 
     * @param attacked the player which has been attacked
     * @param weapon_type the type of waepon used by this player
     * @param same_team determines whether the players are in the same team or not
     */
    void attack(Player& attacked, const std::string weapon_type, const bool same_team);

    /**
     * @brief Manage the properties of the player when being attacked
     * 
     *   Apart from mangement of the properties, this method determines whether the player has died
     * after being attacked or not by returning a boolean type variable.
     * 
     * @param damage the amount of damage which the player has been inflicted with
     * @return true the player is dead
     * @return false the player isn't dead
     */
    bool got_attacked(const int damage);

    /**
     * @brief Detemine wheter the player is dead or not
     * 
     * @return true the player is dead
     * @return false the player is alive
     */
    bool is_dead() const;

    /**
     * @brief Resets some variables when a new round has been started
     * 
     *   Proper amount of money will be given to the player based on
     * whether the player has won the previous round or not. Also if
     * the player has lost the last round, all of his weapons apart from
     * the knife will be discarded. 
     * 
     * @param has_won determines whether the player has won the previous round or not
     */
    void new_round(const bool has_won);

    /**
     * @brief Compare two players
     * 
     * @param second_player the second player
     * @return true this player is superior
     * @return false the second player is superior
     */
    bool operator > (const Player& second_player);

    /**
     * @brief Get the username of the player
     * 
     * @return std::string the player's username
     */
    std::string get_username() const;

    /**
     * @brief Get a copy of the player's statistics
     * 
     * @return PlayerStatistics a copy of the player's statistics
     */
    PlayerStatistics get_statistics() const;

    /**
     * @brief Get the time when the player joined the game
     * 
     * @return Timer the time when the player joined the game
     */
    Timer get_join_time() const;

    /**
     * @brief Get the round when the player joined the game
     * 
     * @return int the round when the player joined the game
     */
    int get_join_round() const;

private:

    /**
     * @brief The player's username
     * 
     */
    std::string username;

    /**
     * @brief the round when the player joined the game
     * 
     */
    int join_round;

    /**
     * @brief the time when the player joined the game
     * 
     */
    Timer join_time;

    /**
     * @brief A WeaponBundle object containing the player's weapons
     * 
     */
    WeaponBundle weapons;

    /**
     * @brief A Player_Statistics object responsible for mangement
     * of the player's statistic information
     * 
     */
    PlayerStatistics statistics;

    static Timer join_dead_line;
    static Timer shop_dead_line;

};

#endif
