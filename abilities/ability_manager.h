#ifndef NAVAL_WARFARE__ABILITY_MANAGER_H_
#define NAVAL_WARFARE__ABILITY_MANAGER_H_

#include "ability.h"
#include "double_damage.h"
#include "scanner.h"
#include "bombard.h"
#include "../exceptions/invalid_ability_usage.h"

class AbilityManager {
 private:
  vector<Ability*> abilities;
 public:
  AbilityManager();
  void apply_ability(pair<int, int> coords, Gamefield* gamefield);
  void add_random_ability();
};


#endif //NAVAL_WARFARE__ABILITY_MANAGER_H_
