#include "ability_manager.h"

AbilityManager::AbilityManager() {
  // Инициализация случайных способностей
  abilities.push_back(new DoubleDamage());
  abilities.push_back(new Scanner());
  abilities.push_back(new Bombard());
}

void AbilityManager::apply_ability(pair<int, int> coords, Gamefield* gamefield) {
  string answer;
  cout << "Хотите использовать способность(Yes/No)?\n";
  cin >> answer;
  getchar();
  while (answer != "No" && answer != "Yes") {
    cout << "Некорректный ответ: " << answer << ". Хотите использовать способность(Yes/No)?\n";
    cin >> answer;
    getchar();
  }
  if (answer == "Yes") {
    if (abilities.empty()) {
      throw Invalid_ability_usage("Ошибка: Нет доступных способностей.");
    }
    srand(time(nullptr));
    int index = rand() % abilities.size();
    abilities[index]->use(coords, gamefield);
    abilities.erase(abilities.begin() + index);  // Удаляем использованную способность
  }
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
  cout << "Получена новая способность!\n";
}

string AbilityManager::ability_manager_to_string() {
  string ability_manager_string = "abilities_amount:" + to_string(abilities.size()) + "\n";
  for (auto ability : abilities) {
    ability_manager_string += ability->ability_to_string() + " ";
  }
  ability_manager_string += "\n";
  return ability_manager_string;
}
