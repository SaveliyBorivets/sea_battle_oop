#ifndef NAVAL_WARFARE__ABILITY_MANAGER_H_
#define NAVAL_WARFARE__ABILITY_MANAGER_H_

#include <sstream>
#include "ability.h"
#include "double_damage.h"
#include "scanner.h"
#include "bombard.h"
#include "../exceptions/invalid_ability_usage.h"
#include "../exceptions/load_error.h"

class AbilityManager {
 private:
  vector<Ability*> abilities;
 public:
  AbilityManager();
  void apply_ability(pair<int, int> coords, Gamefield* gamefield);
  void add_random_ability();
  string ability_manager_to_string();
  void load(string data);
};


#endif //NAVAL_WARFARE__ABILITY_MANAGER_H_
