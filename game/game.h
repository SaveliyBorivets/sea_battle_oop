#ifndef NAVAL_WARFARE_GAME_GAME_H_
#define NAVAL_WARFARE_GAME_GAME_H_

#include "../gamefield/gamefield.h"
#include "../ships/ship_manager.h"
#include "../abilities/ability_manager.h"
#include "game_state.h"
#include <sstream>
#include <stdlib.h>
#include <time.h>

class Game {
 private:
  GameStatus game_status;
  Game_state* game_state;
  Gamefield* player_gamefield;
  Gamefield* computer_gamefield;
  Ship_Manager* player_ship_manager;
  Ship_Manager* computer_ship_manager;
  AbilityManager* player_ability_manager;
  pair<int, int> input_coordinates();
 public:
  Game();
  void game_start(); // Начало игры
  void game_end(); // Конец игры
  void game_save();
  void player_move(); // Ход от игрока
  void computer_move(); // Ход от компьютера
  void rounds(); // Чередование ходов
  void defeat();
  void victory();
};

#endif //NAVAL_WARFARE_GAME_GAME_H_
