#include "ship.h"

// Конструктор корабля, подается длина
Ship::Ship(size_t length) : ship_parts(length, nullptr) {
  ship_length = length;
  destruction_flag = false;
  for (size_t i = 0; i < ship_length; i++) {
    ship_parts[i] = new ShipPart;
  }
}

Ship::Ship(size_t length, string status) : ship_parts(length, nullptr) {
  istringstream stream(status);

  ship_length = length;
  destruction_flag = false;
  int hp;
  for (size_t i = 0; i < ship_length; i++) {
    stream >> hp;
    ship_parts[i] = new ShipPart(static_cast<HealthStatus>(hp));
  }
}

// Вывод визуализированного состояния корабля
void Ship::ship_status() {
  for (size_t i = 0; i < ship_length; i++) {
    ship_parts[i]->part_status();
  }
  cout << endl;
}

bool Ship::update_destruction_flag() {
  for (auto part : ship_parts) {
    if (part->get_hp() != 0) {
      destruction_flag = false;
      return false;
    }
  }
  if (!destruction_flag) {
    destruction_flag = true;
    return true;
  }
  destruction_flag = true;
  return false;
}

// Получение сегментов корабля
vector<ShipPart*> Ship::get_ship_parts() {
  return ship_parts;
}

bool Ship::get_destruction_flag() {
  return destruction_flag;
}

// Получение длины корабля
size_t Ship::get_ship_length() {
  return ship_length;
}

string Ship::ship_to_string() {
  string ship_string;
  for (auto part : ship_parts) {
    ship_string += to_string(part->get_hp()) + " ";
  }
  return ship_string;
}