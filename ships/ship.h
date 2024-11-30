#ifndef NAVAL_WARFARE__SHIP_H_
#define NAVAL_WARFARE__SHIP_H_

#include <iostream>
#include <cstddef>
#include <utility>
#include <vector>
#include <sstream>
#include "shippart.h"

using namespace std;

enum Orientation {
  EMPTY,
  HORIZONTAL,
  VERTICAL
};

class Ship {
 private:
  vector<ShipPart*> ship_parts;
  bool destruction_flag;
  size_t ship_length;
 public:
  Ship(size_t length);
  Ship(size_t length, string status);
  void ship_status();
  bool update_destruction_flag();
  vector<ShipPart*> get_ship_parts();
  bool get_destruction_flag();
  size_t get_ship_length();
  string ship_to_string();
};

#endif //NAVAL_WARFARE__SHIP_H_
