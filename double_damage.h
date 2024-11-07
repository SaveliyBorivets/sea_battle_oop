#ifndef NAVAL_WARFARE__DOUBLE_DAMAGE_H_
#define NAVAL_WARFARE__DOUBLE_DAMAGE_H_

#include "ability.h"

class DoubleDamage : public Ability {
 public:
  void use(pair<int, int> coords, Gamefield* gamefield) override;
 private:
  void print_activation() override;
};

#endif //NAVAL_WARFARE__DOUBLE_DAMAGE_H_
