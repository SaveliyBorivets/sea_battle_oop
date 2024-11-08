#ifndef NAVAL_WARFARE__CELL_H_
#define NAVAL_WARFARE__CELL_H_

#include "../ships/shippart.h"

#define SEA "\x1B[1;44m"
#define SEA_HIT "\x1B[1;30;45m"
#define RESET "\x1B[0m"

class Cell{
 private:
  bool hit_flag;
  ShipPart* shipcell;
 public:
  Cell();
  Cell(const Cell& other); // Копирование
  Cell& operator=(const Cell& other);
  void cell_hit(int amount_of_damage);
  void place_shipcell(ShipPart*);
  void remove_shipcell();
  bool is_shipcell();
  ShipPart* get_shippart();
  void print_cell(bool enemy_flag);
};

#endif //NAVAL_WARFARE__CELL_H_
