#include <iostream>
#include "gamefield/gamefield.h"
#include "ships/ship_manager.h"
#include "abilities/ability_manager.h"
#include "game/game.h"


using namespace std;

int main() {
  Game new_game;
  new_game.game_start();
  new_game.player_move();
  return 0;
}
