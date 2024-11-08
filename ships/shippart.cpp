#include "shippart.h"

// Конструктор сегмента корабля
ShipPart::ShipPart() {
  hp = UNTOUCHED;
}

// Получения количества очков здоровья
size_t ShipPart::get_hp() {
  return hp;
}

// Вывод визуализированного состояния корабля
void ShipPart::part_status() {
  switch(hp) {
    case DESTROYED:
      cout << DESTROYED_PRINT << "  " << RESET << " ";
      break;
    case DAMAGED:
      cout << DAMAGED_PRINT << "  " << RESET << " ";
      break;
    case UNTOUCHED:
      cout << UNTOUCHED_PRINT << "  " << RESET << " ";
      break;
  }
}

// Получение урона
void ShipPart::part_damage(int amount_of_damage) {
  hp = max(0, hp - amount_of_damage);
}