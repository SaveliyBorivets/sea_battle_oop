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

enum GameStatus {
  NOT_STARTED,
  IN_PROCESS,
  VICTORY,
  FAILURE
};

class Game_state {
 private:
  string path_to_save;
  FILE* save_file;
  string player_ship_manager_data;
  string player_gamefield_data;
  string player_ability_manager_data;
  string computer_ship_manager_data;
  string computer_gamefield_data;
 public:
  Game_state(string path_to_save_file = "../saves/slot1.txt");
  void save_game_state(Ship_Manager* PSM, Gamefield* PGF, AbilityManager* PAM, Ship_Manager* CSM, Gamefield* CGF, string path_to_save_file = "../saves/slot1.txt");
  GameStatus get_game_status();
  void set_start();
  void set_victory();
  void set_fail();
};

#endif //NAVAL_WARFARE_GAME_GAME_STATE_H_
