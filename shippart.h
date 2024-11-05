#ifndef NAVAL_WARFARE__SHIPPART_H_
#define NAVAL_WARFARE__SHIPPART_H_

#include <iostream>
#include <cstddef>
#include <utility>

#define UNTOUCHED "\x1B[1;47m"
#define DAMAGED "\x1B[1;43m"
#define DESTROYED "\x1B[1;41m"
#define RESET "\x1B[0m"

using namespace std;

class ShipPart {
 private:
  size_t hp;
  //pair <size_t, size_t> coords;
 public:
  ShipPart();
  size_t get_hp();
  void part_status();
  void part_damage();
};

#endif //NAVAL_WARFARE__SHIPPART_H_
