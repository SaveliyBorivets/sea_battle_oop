#include "ability_manager.h"

AbilityManager::AbilityManager() {
  // Инициализация случайных способностей
  abilities.push_back(new DoubleDamage());
  abilities.push_back(new Scanner());
  abilities.push_back(new Bombard());
}

void AbilityManager::apply_ability(pair<int, int> coords, Gamefield* gamefield) {
  if (abilities.empty()) {
    throw Invalid_ability_usage("Ошибка: Нет доступных способностей.");
  }
  int index = rand() % abilities.size();
  abilities[index]->use(coords, gamefield);
  abilities.erase(abilities.begin() + index);  // Удаляем использованную способность
}

void AbilityManager::add_random_ability() {
  // Добавление случайной способности при уничтожении корабля
  srand(time(nullptr));
  int randomAbility = rand() % 3;
  switch (randomAbility) {
    case 0: abilities.push_back(new DoubleDamage()); break;
    case 1: abilities.push_back(new Scanner()); break;
    case 2: abilities.push_back(new Bombard()); break;
  }
}
