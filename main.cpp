#include <iostream>
#include "gamefield/gamefield.h"
#include "ships/ship_manager.h"
#include "abilities/ability_manager.h"

using namespace std;

int main() {
  Gamefield gamefield = Gamefield(7, 10);
  Ship_Manager ship_manager = Ship_Manager(2, {1, 1});
  AbilityManager ability_manager = AbilityManager();
  ship_manager.place_ships_on_field(&gamefield);
  DoubleDamage().use({0, 0}, &gamefield);
  Bombard().use({0, 0}, &gamefield);
  DoubleDamage().use({0, 0}, &gamefield);
  Bombard().use({0, 0}, &gamefield);
  gamefield.print_gamefield(false);
  ship_manager.remove_ships_from_field(&gamefield);
  gamefield.print_gamefield(false);
  ship_manager.print_ships_status();
  return 0;
}
