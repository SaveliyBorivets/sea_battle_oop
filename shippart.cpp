#include "shippart.h"

// Конструктор сегмента корабля
ShipPart::ShipPart() {
  hp = UNTOUCHED_PART;
}

// Получения количества очков здоровья
size_t ShipPart::get_hp() {
  return hp;
}

// Вывод визуализированного состояния корабля
void ShipPart::part_status() {
  switch(hp) {
    case DESTROYED_PART:
      cout << DESTROYED << "  " << RESET << " ";
      break;
    case DAMAGED_PART:
      cout << DAMAGED << "  " << RESET << " ";
      break;
    case UNTOUCHED_PART:
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