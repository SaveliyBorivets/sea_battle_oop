#ifndef NAVAL_WARFARE__BOMBARD_H_
#define NAVAL_WARFARE__BOMBARD_H_

#include "ability.h"
#include <stdlib.h>
#include <time.h>

class Bombard : public Ability {
 public:
  void use(pair<int, int> coords, Gamefield* gamefield) override;
  string ability_to_string() override;
 private:
  void print_activation() override;
};

#endif //NAVAL_WARFARE__BOMBARD_H_
