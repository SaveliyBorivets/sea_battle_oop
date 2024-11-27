#include "scanner.h"

void Scanner::print_activation() {
  cout << "Активация способности: СКАНИРОВАНИЕ!\n";
  cout << "Сканируем 2x2 область...\n";
}

void Scanner::use(pair<int, int> coords, Gamefield* gamefield) {
  pair<int, int> coords_right_down = {coords.first + 1, coords.second + 1};
  if (gamefield->prove_coords(coords) && gamefield->prove_coords(coords_right_down)) {
    print_activation();
    for (int y = coords.second; y <= coords_right_down.second; y++) {
      for (int x = coords.first; x <= coords_right_down.first; x++) {
        if (gamefield->prove_shipcell({x, y})) {
          cout << "По координатам {" << x << ", " << y << "} найден сегмент корабля\n";
        }
      }
    }
  } else if (gamefield->prove_coords(coords)) {
    if (gamefield->prove_shipcell(coords)) {
      cout << "По координатам {" << coords.first << ", " << coords.second << "} найден сегмент корабля\n";
    }
  } else {
    cout << "Выход за границы поля\n";
  }
}

string Scanner::ability_to_string() {
  return "Scanner";
}