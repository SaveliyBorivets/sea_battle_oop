#ifndef NAVAL_WARFARE__SHIPPART_H_
#define NAVAL_WARFARE__SHIPPART_H_

#include <iostream>
#include <cstddef>
#include <utility>
#include <cstdlib>

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
  int hp;
  //pair <size_t, size_t> coords;
 public:
  ShipPart(HealthStatus health_status = UNTOUCHED);
  size_t get_hp();
  void part_status();
  void part_damage(int amount_of_damage);
};

#endif //NAVAL_WARFARE__SHIPPART_H_
