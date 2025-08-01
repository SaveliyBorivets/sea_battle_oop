#include <sstream>
#include "ship_manager.h"

// Конструктор менеджера, подается количество кораблей и их размеры
Ship_Manager::Ship_Manager(size_t amount, vector<int> ships_sizes) : ships_coords(amount, make_pair(-1, -1)), ships_orientations(amount, EMPTY) {
  ship_amount = amount;
  ships_lengths = ships_sizes;
  for (int i = 0; i < ship_amount; i++) {
    if (!(1 <= ships_lengths[i] && ships_lengths[i] <= 4)) {
      cout << "Некорректная длина:" << ships_lengths[i] << endl;
      ships_lengths[i] = input_length();
    }
    input_orientation(i);
    input_coordinates(i);
    ships.push_back(new Ship(ships_lengths[i]));
  }
}

// Размещение кораблей на поле
void Ship_Manager::place_ships_on_field(Gamefield* gamefield) {
  for (int i = 0; i < ship_amount; i++) {
    while (!gamefield->place_ship(ships[i], ships_coords[i], ships_orientations[i])) {
      cout << "Корабль длиной" << ships_lengths[i] << "не может быть выставлен по введенным координатам {" << ships_coords[i].first << ", " << ships_coords[i].second << "}, попробуйте еще раз" << endl;
      input_orientation(i);
      input_coordinates(i);
    }
  }
}

//void Ship_Manager::random_place_ships_on_field(Gamefield* gamefield) {
//  pair<int, int> random_coords;
//  Orientation random_orientation;
//}

// Удаление кораблей с поля(корабли остаются в менеджере)
void Ship_Manager::remove_ships_from_field(Gamefield* gamefield) {
  for (int i = 0; i < ship_amount; i++) {
    gamefield->remove_ship(ships[i], ships_coords[i], ships_orientations[i]);
  }
}

// Вывод информации о кораблях
void Ship_Manager::print_ship_data(int ship_ind) {
  cout << "Ориентация корабля: ";
  switch (ships_orientations[ship_ind]) {
    case EMPTY:
      cout << "Данные отсутствуют" << endl;
      break;
    case HORIZONTAL:
      cout << "Горизонтальное расположение" << endl;
      break;
    case VERTICAL:
      cout << "Вертикальное расположение" << endl;
      break;
  }
  if (ships_lengths[ship_ind]) {
    cout << "Длина корабля: " << ships_lengths[ship_ind] << endl;
  } else {
    cout << "Данные о длине корабля отсутствуют" << endl;
  }
  if (ships_coords[ship_ind].first != -1 && ships_coords[ship_ind].second != -1) {
    cout << "Координаты корабля: (" << ships_coords[ship_ind].first << "; " << ships_coords[ship_ind].second << ")" << endl;
  } else {
    cout << "Координаты отсутствуют" << endl;
  }
}

// Вывод визуализированного состояния сегментов корабло
void Ship_Manager::print_ships_status() {
  for(int i = 0; i < ship_amount; i++) {
    ships[i]->ship_status();
    print_ship_data(i);
  }
}

// Ввод длины корабля
int Ship_Manager::input_length() {
  cout << "Введите длину корабля от 1 до 4: ";
  int length;
  cin >> length;
  getchar();
  while(!(1 <= length && length <= 4)) {
    cout << "Некорректная длина корабля(от 1 до 4). Попробуйте ещё раз: ";
    cin >> length;
    getchar();
  }
  return length;
}

// Ввод ориентации
void Ship_Manager::input_orientation(size_t ship_ind) {
  string input_orientation;
  cout << "Введите ориентацию корабля(horizontal/vertical): ";
  cin >> input_orientation;
  getchar();
  while(input_orientation != "horizontal" && input_orientation != "vertical") {
    cout << "Некорректная ориентация: " << input_orientation << ". Попробуйте ещё раз(horizontal/vetrical): ";
    cin >> input_orientation;
    getchar();
  }
  Orientation orientation;
  if (input_orientation == "horizontal") {
    orientation = HORIZONTAL;
  } else {
    orientation = VERTICAL;
  }
  ships_orientations[ship_ind] = orientation;
}

// Ввод координат
void Ship_Manager::input_coordinates(size_t ship_ind) {
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
    ships_coords[ship_ind] = make_pair(x, y);
    return;
  }
}

bool Ship_Manager::is_all_destroyed() {
  for (auto cur_ship : ships) {
    if (!cur_ship->get_destruction_flag()) {
      return false;
    }
  }
  return true;
}

bool Ship_Manager::update_all_ship_destruction_flags() {
  for (auto cur_ship : ships) {
    if (cur_ship->update_destruction_flag()) {
      return true;
    }
  }
  return false;
}

string Ship_Manager::ship_manager_to_string() {
  string ship_manager_string;
  ship_manager_string += "ship_amount:" + to_string(ship_amount) + "\n";
  for (int i = 0; i < ship_amount; i++) {
    ship_manager_string += "length:" + to_string(ships_lengths[i]) + "\n";
    ship_manager_string += "coordinates:" + to_string(ships_coords[i].first) + " " + to_string(ships_coords[i].second) + "\n";
    ship_manager_string += "orientation:" + to_string(ships_orientations[i]) + "\n";
    ship_manager_string += "status:" + ships[i]->ship_to_string() + "\n";
  }
  return ship_manager_string;
}

void Ship_Manager::load(string data) {
  ships_lengths.clear();
  ships.clear();
  ships_coords.clear();
  ships_orientations.clear();

  std::istringstream stream(data);
  std::string line;
  pair<int, int> coords;

  getline(stream, line);
  size_t pos = line.find(':') + 1;
  if (pos != std::string::npos) {
    ship_amount = std::stoi(line.substr(pos));
  }
  for (int i = 0; i < ship_amount; i++) {
    getline(stream, line);
    pos = line.find(':') + 1;
    if (pos != std::string::npos) {
      ships_lengths.push_back(stoi(line.substr(pos)));
    }
    getline(stream, line);
    pos = line.find(':') + 1;
    if (pos != std::string::npos) {
      std::istringstream coord_stream(line.substr(pos));
      coord_stream >> coords.first >> coords.second;
      ships_coords.push_back(coords);
    }
    getline(stream, line);
    pos = line.find(':') + 1;
    if (pos != std::string::npos) {
      switch (stoi(line.substr(pos))) {
        case VERTICAL:
          ships_orientations.push_back(VERTICAL);
          break;
        case HORIZONTAL:
          ships_orientations.push_back(HORIZONTAL);
          break;
      }
    }
    getline(stream, line);
    pos = line.find(':') + 1;
    if (pos != std::string::npos) {
      ships.push_back(new Ship(ships_lengths[i], line.substr(pos)));
    }
  }
}