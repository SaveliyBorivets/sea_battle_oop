#include <iostream>
#include "gamefield.h"
#include "ship_manager.h"

using namespace std;

int main() {
  Gamefield gamefield = Gamefield(7, 10);
  Ship_Manager manager = Ship_Manager(2, {4, 2});
  manager.place_ships_on_field(&gamefield);
  gamefield.field_take_hit(make_pair(0, 0));
  gamefield.field_take_hit(make_pair(0, 0));
  gamefield.field_take_hit(make_pair(0, 1));
  gamefield.field_take_hit(make_pair(5, 5));
  gamefield.print_gamefield(false);
  gamefield.print_gamefield(true);
  manager.remove_ships_from_field(&gamefield);
  gamefield.print_gamefield(false);
  manager.print_ships_status();
  return 0;
}
