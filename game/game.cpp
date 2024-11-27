#include "game.h"

Game::Game() : gamefield(10,10), ship_manager(1, {1}), ability_manager() {}

void Game::game_start() {
  ship_manager.place_ships_on_field(&gamefield);
}

void Game::player_move() {
  pair<int, int> action_coordinates;
  while (!ship_manager.is_all_destroyed()) {
    gamefield.print_gamefield();
    action_coordinates = input_coordinates();
    ability_manager.apply_ability(action_coordinates, &gamefield);
    gamefield.field_take_hit(action_coordinates);
    ship_manager.update_all_ship_destruction_flags();
  }
  gamefield.print_gamefield();
  cout << "Игра закончилась" << endl;
}

pair<int, int> Game::input_coordinates() {
  while (true) {
    string user_input;
    cout << "Введите координаты в формате \"x y\": ";
    getline(cin, user_input);
    istringstream iss(user_input);
    int x, y;
    if (!(iss >> x >> y)) {
      cout << "Координаты введены неправильно, попробуйте ввести снова в формате \"x y\": " << endl;
      continue;
    }
    if (iss.rdbuf()->in_avail() != 0) {
      cout << "Координаты введены неправильно. Дополнительные символы после координат." << endl;
      continue;
    }
    return {x, y};
  }
}