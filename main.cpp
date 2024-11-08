#include <iostream>
#include "gamefield/gamefield.h"
#include "ships/ship_manager.h"
#include "abilities/ability_manager.h"

using namespace std;

int main() {
  Gamefield gamefield = Gamefield(7, 10);
  Ship_Manager ship_manager = Ship_Manager(2, {1, 3});
  AbilityManager ability_manager = AbilityManager();
  ship_manager.place_ships_on_field(&gamefield);
  ability_manager.apply_ability({2, 2}, &gamefield);
  gamefield.field_take_hit({0, 0}, 1);
  if (ship_manager.update_all_ship_destruction_flags()) {
    ability_manager.add_random_ability();
  }
  gamefield.field_take_hit({0, 0}, 1);
  if (ship_manager.update_all_ship_destruction_flags()) {
    ability_manager.add_random_ability();
  }
  gamefield.print_gamefield(false);
  ship_manager.remove_ships_from_field(&gamefield);
  gamefield.print_gamefield(false);
  ship_manager.print_ships_status();
  return 0;
}
