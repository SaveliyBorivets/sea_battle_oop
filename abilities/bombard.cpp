#include "bombard.h"

void Bombard::print_activation() {
  cout << "Активация способности: ОБСТРЕЛ!\n";
  cout << "Ищем цель...\n";
}

void Bombard::use(pair<int, int> coords, Gamefield* gamefield) {
  vector<pair<int, int>> all_shipcells_coords;
  for (int y = 0; y < gamefield->get_field_height(); y++) {
    for (int x = 0; x < gamefield->get_field_width(); x++) {
      pair<int, int> field_cell_coords = {x, y};
      if (gamefield->prove_shipcell(field_cell_coords) && gamefield->get_cell(field_cell_coords)->get_shippart()->get_hp() > 0) {
        all_shipcells_coords.push_back(field_cell_coords);
      }
    }
  }
  srand(time(nullptr));
  if (!all_shipcells_coords.empty()) {
    print_activation();
    int hit_index = rand() % all_shipcells_coords.size();
    gamefield->field_take_hit(all_shipcells_coords[hit_index]);
  }
}

string Bombard::ability_to_string() {
  return "Bombard";
}