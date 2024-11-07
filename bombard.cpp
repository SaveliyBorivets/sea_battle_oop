#include "bombard.h"

void Bombard::print_activation() {
  cout << "Активация способности: ОБСТРЕЛ!\n";
  cout << "Подготавливаем снаряды...\n";
}

void Bombard::use(pair<int, int> coords, Gamefield* gamefield) {
  vector<Cell*> all_shipcells;
  for (int y = 0; y < gamefield->get_field_height(); y++) {
    for (int x = 0; x < gamefield->get_field_width(); x++) {
      pair<int, int> field_cell = {x, y};
      if (gamefield->prove_shipcell(field_cell) && gamefield->get_cell(field_cell)->get_shippart()->get_hp() > 0) {
        all_shipcells.push_back(gamefield->get_cell(field_cell));
      }
    }
  }
  srand(time(nullptr));
  if (!all_shipcells.empty()) {
    print_activation();
    int hit_index = rand() % all_shipcells.size();
    all_shipcells[hit_index]->cell_hit();
  }
}