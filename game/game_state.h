//
// Created by homie on 27.11.24.
//

#ifndef NAVAL_WARFARE_GAME_GAME_STATE_H_
#define NAVAL_WARFARE_GAME_GAME_STATE_H_

#include <iostream>
#include <fstream>
#include "../gamefield/gamefield.h"
#include "../ships/ship_manager.h"
#include "../abilities/ability_manager.h"

#define PLAYER_SHIP_MANAGER "===PLAYER_SHIP_MANAGER==="
#define PLAYER_GAMEFIELD "===PLAYER_GAMEFIELD==="
#define PLAYER_ABILITY_MANAGER "===PLAYER_ABILITY_MANAGER==="
#define COMPUTER_SHIP_MANAGER "===COMPUTER_SHIP_MANAGER==="
#define COMPUTER_GAMEFIELD "===COMPUTER_GAMEFIELD==="

enum Datapack {
  PLAYER_SHIP_MANAGER_DATA,
  PLAYER_GAMEFIELD_DATA,
  PLAYER_ABILITY_MANAGER_DATA,
  COMPUTER_SHIP_MANAGER_DATA,
  COMPUTER_GAMEFIELD_DATA
};

class Game_state {
 private:
  string path_to_save_file;
  string player_ship_manager_data;
  string player_gamefield_data;
  string player_ability_manager_data;
  string computer_ship_manager_data;
  string computer_gamefield_data;
 public:
  Game_state(string path_to_save_file = "../saves/slot1.txt");
  void set_path_to_save_file(string path_to_save = "../saves/slot1.txt");
  void load_game_state();
  void save_game_state(Ship_Manager* PSM, Gamefield* PGF, AbilityManager* PAM, Ship_Manager* CSM, Gamefield* CGF);
  string get_datapack(Datapack datapack);
  void clear();
  string get_path();
};

#endif //NAVAL_WARFARE_GAME_GAME_STATE_H_
