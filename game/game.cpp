#include "game.h"

Game::Game() {
  game_status = NOT_STARTED;
  game_state = nullptr;
  player_gamefield = nullptr;
  computer_gamefield = nullptr;
  player_ship_manager = nullptr;
  computer_ship_manager = nullptr;
  player_ability_manager = nullptr;
}

void Game::game_start() {
  game_state = new Game_state();
  new_game();
  while (true) {
    rounds();
    if (player_ship_manager->is_all_destroyed()) {
      cout << "ПОРАЖЕНИЕ" << endl;
      cout << "Начинаем новую игру!" << endl;
      new_game();
    } else {
      cout << "ПОБЕДА" << endl;
      cout << "Ищем нового противника" << endl;
      computer_gamefield = new Gamefield(10, 10);
      computer_ship_manager = new Ship_Manager(1, {1});
      computer_ship_manager->place_ships_on_field(computer_gamefield);
    }
  }
}

void Game::new_game() {
  player_gamefield = new Gamefield(10, 10);
  computer_gamefield = new Gamefield(10, 10);
  player_ship_manager = new Ship_Manager(1, {1});
  computer_ship_manager = new Ship_Manager(1, {1});
  player_ability_manager = new AbilityManager();
  player_ship_manager->place_ships_on_field(player_gamefield);
  computer_ship_manager->place_ships_on_field(computer_gamefield);
}

void Game::game_save() {
  string answer;
  cout << "Хотите сохранить игру(Yes/No)?\n";
  cin >> answer;
  getchar();
  while (answer != "No" && answer != "Yes") {
    cout << "Некорректный ответ: " << answer << ". Хотите сохранить игру(Yes/No)?\n";
    cin >> answer;
    getchar();
  }
  if (answer == "Yes") {
    game_state->save_game_state(player_ship_manager, player_gamefield, player_ability_manager, computer_ship_manager, computer_gamefield);
  }
}

void Game::game_load() {
  string answer;
  cout << "Хотите загрузить игру(Yes/No)?\n";
  cin >> answer;
  getchar();
  while (answer != "No" && answer != "Yes") {
    cout << "Некорректный ответ: " << answer << ". Хотите загрузить игру(Yes/No)?\n";
    cin >> answer;
    getchar();
  }
  if (answer == "Yes") {
    game_state->load_game_state();
    player_ship_manager->load(game_state->get_datapack(PLAYER_SHIP_MANAGER_DATA));
    player_gamefield->load(game_state->get_datapack(PLAYER_GAMEFIELD_DATA));
    player_ship_manager->place_ships_on_field(player_gamefield);
    player_ability_manager->load(game_state->get_datapack(PLAYER_ABILITY_MANAGER_DATA));
    computer_ship_manager->load(game_state->get_datapack(COMPUTER_SHIP_MANAGER_DATA));
    computer_gamefield->load(game_state->get_datapack(COMPUTER_GAMEFIELD_DATA));
    computer_ship_manager->place_ships_on_field(computer_gamefield);
  }
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
    game_save();
    game_load();
    player_move();
    if (!computer_ship_manager->is_all_destroyed()) {
      computer_move();
    }
  }
  cout << "Раунд закончился!" << endl;
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