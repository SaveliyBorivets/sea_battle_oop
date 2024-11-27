#include "game.h"

Game::Game() {
  player_gamefield = new Gamefield(10, 10);
  computer_gamefield = new Gamefield(10, 10);
  player_ship_manager = new Ship_Manager(1, {1});
  computer_ship_manager = new Ship_Manager(1, {1});
  player_ability_manager = new AbilityManager();
}

void Game::game_start() {
  player_ship_manager->place_ships_on_field(player_gamefield);
  computer_ship_manager->place_ships_on_field(computer_gamefield);
}

void Game::player_move() {
  cout << "ВАШ ХОД!" << endl;
  computer_gamefield->print_gamefield();
  pair<int, int> action_coordinates = input_coordinates();
  player_ability_manager->apply_ability(action_coordinates, computer_gamefield);
  computer_gamefield->field_take_hit(action_coordinates);
  if (computer_ship_manager->update_all_ship_destruction_flags()) {
    player_ability_manager->add_random_ability();
  }
  computer_gamefield->print_gamefield();
}

void Game::computer_move() {
  cout << "ХОД ПРОТИВНИКА!" << endl;
  srand(time(nullptr));
  int x = rand() % player_gamefield->get_field_width();
  int y = rand() % player_gamefield->get_field_height();
  pair<int, int> action_coordinates = {x, y};
  player_gamefield->field_take_hit(action_coordinates);
  player_gamefield->print_gamefield();
  if (player_ship_manager->update_all_ship_destruction_flags()) {
    cout << "Потеря! Противник уничтожил корабль!" << endl;
  }
}

void Game::rounds() {
  while (!player_ship_manager->is_all_destroyed() && !computer_ship_manager->is_all_destroyed()) {
    player_move();
    if (computer_ship_manager->is_all_destroyed()) {
      cout << "ПОБЕДА!" << endl;
    } else {
      computer_move();
    }
  }
  cout << "Игра закончилась!" << endl;
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