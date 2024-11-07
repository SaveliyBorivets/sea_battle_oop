#ifndef NAVAL_WARFARE__ABILITY_H_
#define NAVAL_WARFARE__ABILITY_H_

#include "gamefield.h"

class Ability {
 public:
  virtual void use(pair<int, int> coords, Gamefield* gamefield) = 0;
  virtual void print_activation() = 0;
};

#endif //NAVAL_WARFARE__ABILITY_H_
