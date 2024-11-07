#include "cell.h"

// Конструктор клетки
Cell::Cell() {
  hit_flag = false;
  shipcell = nullptr;
};

// Конструктор копирования клетки
Cell::Cell(const Cell& other) : hit_flag(other.hit_flag), shipcell(other.shipcell) {}

// Оператор копирования клетки
Cell& Cell::operator=(const Cell& other) {
  if (this != &other) {
    hit_flag = other.hit_flag;
    shipcell = other.shipcell;
  }
  return *this;
}

// Получение урона клеткой
void Cell::cell_hit() {
  if (is_shipcell()) {
    shipcell->part_damage();
  } else {
    hit_flag = true;
  }
}

// Выставление корабля
void Cell::place_shipcell(ShipPart* ship_part) {
  shipcell = ship_part;
}

// Удаление сегмента корабля с поля
void Cell::remove_shipcell() {
  shipcell = nullptr;
}

// Проверка на наличие сегмента в клетке
bool Cell::is_shipcell() {
  if (shipcell != nullptr) {
    return true;
  }
  return false;
}

ShipPart* Cell::get_shippart() {
  return shipcell;
}

// Визуализированный вывод клетки
void Cell::print_cell(bool enemy_flag) {
  if (is_shipcell()) {
    if (shipcell->get_hp() == 2 && enemy_flag) {
      cout << SEA << "  " << RESET << " ";
    } else {
      shipcell->part_status();
    }
  } else {
    if (hit_flag) {
      cout << SEA_HIT << "XX" << RESET << " ";
    } else {
      cout << SEA << "  " << RESET << " ";
    }
  }
}