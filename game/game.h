#ifndef NAVAL_WARFARE_GAME_GAME_H_
#define NAVAL_WARFARE_GAME_GAME_H_

#include "player.h"
#include "game_state.h"
#include <sstream>

class Game {
 private:
  Gamefield gamefield;
  Ship_Manager ship_manager;
  AbilityManager ability_manager;
  pair<int, int> input_coordinates();
 public:
  Game();
  void game_start(); // Начало игры
  void player_move(); // Ход от игрока
  void computer_move(); // Ход от компьютера
  void defeat();
  void victory();
  GameStatus get_game_state();
};

#endif //NAVAL_WARFARE_GAME_GAME_H_
