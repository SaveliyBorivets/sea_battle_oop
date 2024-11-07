#ifndef NAVAL_WARFARE__SHIPPART_H_
#define NAVAL_WARFARE__SHIPPART_H_

#include <iostream>
#include <cstddef>
#include <utility>

#define DESTROYED_PRINT "\x1B[1;41m"
#define DAMAGED_PRINT "\x1B[1;43m"
#define UNTOUCHED_PRINT "\x1B[1;47m"
#define RESET "\x1B[0m"

using namespace std;

enum HealthStatus {
  DESTROYED,
  DAMAGED,
  UNTOUCHED
};

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
