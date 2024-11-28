#include "game_state.h"

Game_state::Game_state(string path_to_save) {
  set_path_to_save_file(path_to_save);
}

void Game_state::set_path_to_save_file(string path_to_save) {
  path_to_save_file = path_to_save;
}

void Game_state::load_game_state() {
  clear();
  ifstream in(path_to_save_file);
  string line;
  int current_pack = -1;
  if (in.is_open())
  {
    while (getline(in, line)) {
      if (line[0] == '=') {
        current_pack++;
        continue;
      }
      switch (current_pack) {
        case PLAYER_SHIP_MANAGER_DATA:
          player_ship_manager_data += line + "\n";
          break;
        case PLAYER_GAMEFIELD_DATA:
          player_gamefield_data += line + "\n";
          break;
        case PLAYER_ABILITY_MANAGER_DATA:
          player_ability_manager_data += line + "\n";
          break;
        case COMPUTER_SHIP_MANAGER_DATA:
          computer_ship_manager_data += line + "\n";
          break;
        case COMPUTER_GAMEFIELD_DATA:
          computer_gamefield_data += line + "\n";
          break;
      }
    }
  }
  in.close();
}

void Game_state::save_game_state(Ship_Manager* PSM, Gamefield* PGF, AbilityManager* PAM, Ship_Manager* CSM, Gamefield* CGF) {
  ofstream out(path_to_save_file);
  if (out.is_open()) {
    out << PLAYER_SHIP_MANAGER << endl << PSM->ship_manager_to_string();
    out << PLAYER_GAMEFIELD << endl << PGF->gamefield_to_string();
    out << PLAYER_ABILITY_MANAGER << endl << PAM->ability_manager_to_string();
    out << COMPUTER_SHIP_MANAGER << endl << CSM->ship_manager_to_string();
    out << COMPUTER_GAMEFIELD << endl << CGF->gamefield_to_string();
    cout << "Игра успешно сохранена!" << std::endl;
  }
  out.close();
}

string Game_state::get_datapack(Datapack datapack) {
  string needed_datapack;
  switch (datapack) {
    case PLAYER_SHIP_MANAGER_DATA:
      needed_datapack = player_ship_manager_data;
      break;
    case PLAYER_GAMEFIELD_DATA:
      needed_datapack = player_gamefield_data;
      break;
    case PLAYER_ABILITY_MANAGER_DATA:
      needed_datapack = player_ability_manager_data;
      break;
    case COMPUTER_SHIP_MANAGER_DATA:
      needed_datapack = computer_ship_manager_data;
      break;
    case COMPUTER_GAMEFIELD_DATA:
      needed_datapack = computer_gamefield_data;
      break;
  }
  return needed_datapack;
}

void Game_state::clear() {
  player_ship_manager_data.clear();
  player_gamefield_data.clear();
  player_ability_manager_data.clear();
  computer_ship_manager_data.clear();
  computer_gamefield_data.clear();
}