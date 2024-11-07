#include "double_damage.h"

void DoubleDamage::print_activation() {
  cout << "Активация способности: ДВОЙНОЙ УРОН!\n";
  cout << "Целимся...\n";
}

void DoubleDamage::use(pair<int, int> coords, Gamefield* gamefield) {
  if (gamefield->prove_coords(coords)) {
    print_activation();
    gamefield->field_take_hit(coords);
    gamefield->field_take_hit(coords);
  } else {
    cout << "Выход за границы поля\n";
  }
}