#include "shippart.h"

// Конструктор сегмента корабля
ShipPart::ShipPart() {
  hp = 2;
}

// Получения количества очков здоровья
size_t ShipPart::get_hp() {
  return hp;
}

// Вывод визуализированного состояния корабля
void ShipPart::part_status() {
  switch(hp) {
    case 0:
      cout << DESTROYED << "  " << RESET << " ";
      break;
    case 1:
      cout << DAMAGED << "  " << RESET << " ";
      break;
    case 2:
      cout << UNTOUCHED << "  " << RESET << " ";
      break;
  }
}

// Получение урона
void ShipPart::part_damage() {
  if (hp > 0) {
    hp--;
  }
}