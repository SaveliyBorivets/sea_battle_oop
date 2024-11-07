#include <iostream>
#include "gamefield.h"
#include "ship_manager.h"
#include "scanner.h"
#include "bombard.h"

using namespace std;

int main() {
  Gamefield gamefield = Gamefield(7, 10);
  Ship_Manager manager = Ship_Manager(2, {4, 2});
  manager.place_ships_on_field(&gamefield);
//  Bombard lol;
//  lol.use({2, 2}, &gamefield);
  gamefield.field_take_hit({10, 10});
  gamefield.print_gamefield(false);
  manager.remove_ships_from_field(&gamefield);
  gamefield.print_gamefield(false);
  manager.print_ships_status();
  return 0;
}
