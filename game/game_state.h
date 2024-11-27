//
// Created by homie on 27.11.24.
//

#ifndef NAVAL_WARFARE_GAME_GAME_STATE_H_
#define NAVAL_WARFARE_GAME_GAME_STATE_H_

enum GameStatus {
  END,
  IN_PROCESS
};

class Game_state {
 private:
  GameStatus game_status;
 public:
  Game_state();
  GameStatus get_game_status();
};

#endif //NAVAL_WARFARE_GAME_GAME_STATE_H_
