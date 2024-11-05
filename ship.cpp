#include "ship.h"

// Конструктор корабля, подается длина
Ship::Ship(size_t length) : ship_parts(length, nullptr) {
  ship_length = length;
  for (size_t i = 0; i < ship_length; i++) {
    ship_parts[i] = new ShipPart;
  }
}

// Вывод визуализированного состояния корабля
void Ship::ship_status() {
  for (size_t i = 0; i < ship_length; i++) {
    ship_parts[i]->part_status();
  }
  cout << endl;
}

// Получение сегментов корабля
vector<ShipPart*> Ship::get_ship_parts() {
  return ship_parts;
}

// Получение длины корабля
size_t Ship::get_ship_length() {
  return ship_length;
}