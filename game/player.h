#ifndef NAVAL_WARFARE_GAME_PLAYER_H_
#define NAVAL_WARFARE_GAME_PLAYER_H_

#include "../gamefield/gamefield.h"
#include "../ships/ship_manager.h"
#include "../abilities/ability_manager.h"

class Player {
 private:
  Gamefield gamefield;
  Ship_Manager ship_manager;
  AbilityManager ability_manager;
 public:
  Player();
};

#endif //NAVAL_WARFARE_GAME_PLAYER_H_
