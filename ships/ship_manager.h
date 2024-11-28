#ifndef NAVAL_WARFARE__SHIP_MANAGER_H_
#define NAVAL_WARFARE__SHIP_MANAGER_H_

#include <iostream>
#include <vector>
#include "ship.h"
#include "../gamefield/gamefield.h"

class Ship_Manager {
 private:
  size_t ship_amount;
  vector<int> ships_lengths;
  vector<Ship*> ships;
  vector<pair<int, int>> ships_coords;
  vector<Orientation> ships_orientations;
  int input_length();
  void input_orientation(size_t ship_ind);
  void input_coordinates(size_t ship_ind);
  void print_ship_data(int ship_ind);
 public:
  Ship_Manager(size_t amount, vector<int> ships_sizes);
  void place_ships_on_field(Gamefield* gamefield);
  void remove_ships_from_field(Gamefield* gamefield);
  bool update_all_ship_destruction_flags();
  bool is_all_destroyed();
  void print_ships_status();
  string ship_manager_to_string();
  void load(string data);
};

#endif //NAVAL_WARFARE__SHIP_MANAGER_H_
