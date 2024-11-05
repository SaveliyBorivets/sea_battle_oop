#include "gamefield.h"

// Конструктор игрового поля, принимает на вход длину и ширину
Gamefield::Gamefield(int width, int height) : field_width(width), field_height(height), field(height, vector<Cell*> (width, nullptr)) {
  for (size_t y = 0; y < field_height; y++) {
    for (size_t x = 0; x < field_width; x++) {
      field[y][x] = new Cell();
    }
  }
}

// Оператор копирования
Gamefield& Gamefield::operator=(const Gamefield& other) {
  if (this != &other) {
    field_width = other.field_width;
    field_height = other.field_height;
    field.clear();
    field.resize(other.field.size());
    for (size_t i = 0; i < other.field.size(); ++i) {
      field[i].resize(other.field[i].size());
      for (size_t j = 0; j < other.field[i].size(); ++j) {
        field[i][j] = std::move(other.field[i][j]);
      }
    }
  }
  return *this;
}

// Конструктор копирования
Gamefield::Gamefield(const Gamefield& other) : field_width(other.field_width), field_height(other.field_height) {
  field.resize(other.field.size());
  for (size_t i = 0; i < other.field.size(); ++i) {
    field[i].resize(other.field[i].size());
    for (size_t j = 0; j < other.field[i].size(); ++j) {
      field[i][j] = new Cell(*other.field[i][j]);
    }
  }
}

//Оператор перемещения
Gamefield& Gamefield::operator=(Gamefield&& other) noexcept {
  if (this != &other) {
    field_width = other.field_width;
    field_height = other.field_height;
    other.field_height = 0;
    other.field_width = 0;
    field = std::move(other.field);
  }
  return *this;
}

// Конструктор перемещения
Gamefield::Gamefield(Gamefield&& other) noexcept : field_width(other.field_width), field_height(other.field_height), field(std::move(other.field)) {
  other.field_height = 0;
  other.field_width = 0;
}

// Проверка вхождения координат в поле
bool Gamefield::prove_coords(pair<int, int> coords) {
  int x = coords.first;
  int y = coords.second;
  if (x < 0 || y < 0 || x >= field_width || y >= field_height) {
    return false;
  }
  return true;
}

// Функция проверяет, можно ли поставить сегмент корабля на поданные координаты
bool Gamefield::prove_placeability(pair<int, int> coords) {
  int x_place = coords.first;
  int y_place = coords.second;
  if (!prove_coords(coords)) return false;
  for (int y = max(y_place - 1, 0); y <= min(y_place + 1, field_height - 1); y++) {
    for (int x = max(x_place - 1, 0); x <= min(x_place + 1, field_width - 1); x++) {
      if (field[y][x]->is_shipcell()) {
        return false;
      }
    }
  }
  return true;
}

// Функция размещения корабля
bool Gamefield::place_ship(Ship* ship, pair<int, int> start_coords, Orientation orientation) {
  vector<ShipPart*> ship_parts = ship->get_ship_parts();
  pair<int, int> coords = start_coords;

  for (int i = 0; i < ship->get_ship_length(); i++) {
    if (!prove_placeability(coords)) {
      cout << "Корабль не может быть расположен в этом месте" << endl;
      return false;
    }
    if (orientation == HORIZONTAL) {
      coords.first++;
    } else {
      coords.second++;
    }
  }

  coords = start_coords;
  for (int i = 0; i < ship->get_ship_length(); i++) {
    field[coords.second][coords.first]->place_shipcell(ship_parts[i]);
    if (orientation == HORIZONTAL) {
      coords.first++;
    } else {
      coords.second++;
    }
  }
  return true;
}

// Функция удаления корабля
void Gamefield::remove_ship(Ship* ship, pair<int, int> start_coords, Orientation orientation) {
  for (int i = 0; i < ship->get_ship_length(); i++) {
    if (prove_coords(start_coords)) {
      field[start_coords.second][start_coords.first]->remove_shipcell();
    }
    if (orientation == HORIZONTAL) {
      start_coords.first++;
    } else if (orientation == VERTICAL) {
      start_coords.second++;
    }
  }
}

// Функция попадания в поле
void Gamefield::field_take_hit(pair<int, int> coords) {
  int x = coords.first;
  int y = coords.second;
  if (prove_coords(coords)) {
    field[y][x]->cell_hit();
  }
}

// Вывод поля
void Gamefield::print_gamefield(bool enemy_flag) {
  for (size_t y = 0; y < field_height; y++) {
    for (size_t x = 0; x < field_width; x++) {
      field[y][x]->print_cell(enemy_flag);
    }
    cout << endl << endl;
  }
  cout << endl;
}