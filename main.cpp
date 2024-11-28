#include <iostream>
#include "gamefield/gamefield.h"
#include "ships/ship_manager.h"
#include "abilities/ability_manager.h"
#include "game/game.h"


using namespace std;

int main() {
  Game new_game;
  new_game.game_start();
//  Gamefield gamefield = Gamefield(10, 10);
//  Ship_Manager ship_manager = Ship_Manager(2, {3, 3});
//  ship_manager.place_ships_on_field(&gamefield);
//  FILE* slot = fopen("../saves/slot1.txt", "w+");
  return 0;
}
