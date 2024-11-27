#include "game_state.h"

Game_state::Game_state() {
  game_status = IN_PROCESS;
}

GameStatus Game_state::get_game_status() {
  return game_status;
}