#ifndef NAVAL_WARFARE__GAMEFIELD_H_
#define NAVAL_WARFARE__GAMEFIELD_H_

#include <vector>
#include <iostream>
#include <algorithm>
#include "cell.h"
#include "ship.h"
#include "exceptions/attack_out_of_bound.h"
#include "exceptions/ship_placement_error.h"

class Gamefield {
 private:
  vector<vector<Cell*>> field;
  int field_width;
  int field_height;
 public:
  Gamefield(int width, int height);
  Gamefield(const Gamefield& other);//Копирование
  Gamefield& operator=(const Gamefield& other);
  Gamefield(Gamefield&& other) noexcept;//Перемещение
  Gamefield& operator=(Gamefield&& other) noexcept;
  bool prove_coords(pair<int, int> coords);
  bool prove_placeability(pair<int, int> coords);
  bool prove_shipcell(pair<int, int> coords);
  bool place_ship(Ship* ship, pair<int, int> start_coords, Orientation orientation);
  void remove_ship(Ship* ship, pair<int, int> start_coords, Orientation orientation);
  void field_take_hit(pair<int, int> coords);
  int get_field_width();
  int get_field_height();
  Cell* get_cell(pair<int, int> coords);
  void print_gamefield(bool enemy_flag);
};

#endif //NAVAL_WARFARE__GAMEFIELD_H_
