#include "game_state.h"

Game_state::Game_state(string path_to_save_file) {
  FILE* save_file = fopen(path_to_save_file.c_str(), "r+");
}

void Game_state::save_game_state(Ship_Manager* PSM, Gamefield* PGF, AbilityManager* PAM, Ship_Manager* CSM, Gamefield* CGF, string path_to_save_file) {
  ofstream out;
  out.open(path_to_save_file);
  if (out.is_open()) {
    out << PLAYER_SHIP_MANAGER << endl << PSM->ship_manager_to_string();
    out << PLAYER_GAMEFIELD << endl << PGF->gamefield_to_string();
    out << PLAYER_ABILITY_MANAGER << endl << PAM->ability_manager_to_string();
    out << COMPUTER_SHIP_MANAGER << endl << CSM->ship_manager_to_string();
    out << COMPUTER_GAMEFIELD << endl << CGF->gamefield_to_string();
  }
  out.close();
  cout << "File has been written" << std::endl;
}
