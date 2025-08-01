#ifndef NAVAL_WARFARE__DOUBLE_DAMAGE_H_
#define NAVAL_WARFARE__DOUBLE_DAMAGE_H_

#include "ability.h"
#include "../exceptions/attack_out_of_bound.h"

class DoubleDamage : public Ability {
 public:
  void use(pair<int, int> coords, Gamefield* gamefield) override;
  string ability_to_string() override;
 private:
  void print_activation() override;
};

#endif //NAVAL_WARFARE__DOUBLE_DAMAGE_H_
