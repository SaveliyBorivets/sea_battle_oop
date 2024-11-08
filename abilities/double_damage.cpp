#include "double_damage.h"

#define DOUBLE_DAMAGE 2

void DoubleDamage::print_activation() {
  cout << "Активация способности: ДВОЙНОЙ УРОН!\n";
  cout << "Целимся...\n";
}

void DoubleDamage::use(pair<int, int> coords, Gamefield* gamefield) {
  if (gamefield->prove_coords(coords)) {
    print_activation();
    gamefield->field_take_hit(coords, DOUBLE_DAMAGE);
  } else {
    throw Attack_out_of_bound("Ошибка: Атака за границы поля {" + to_string(coords.first) + ", " + to_string(coords.second) + "}.");;
  }
}