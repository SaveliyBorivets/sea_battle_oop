#ifndef NAVAL_WARFARE__SCANNER_H_
#define NAVAL_WARFARE__SCANNER_H_

#include "ability.h"

class Scanner : public Ability {
 public:
  void use(pair<int, int> coords, Gamefield* gamefield) override;
 private:
  void print_activation() override;
};

#endif //NAVAL_WARFARE__SCANNER_H_
