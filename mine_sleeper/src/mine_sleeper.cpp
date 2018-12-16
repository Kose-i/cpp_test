#include <iostream>
#include <vector>
#include <bitset>
#include <string>
#include <utility>
#include <random>

#include "mine_sleeper.hpp"

  /*
     012
     3*4
     567
   */
Mine_sleeper::Mine_sleeper(): board(9,std::vector<std::string>(9,"■")), answer_Board(9,std::vector<char>(9,'0'))
{};
Mine_sleeper::~Mine_sleeper(){}

void Mine_sleeper::init()
{
  bom_pos_init();
  board_init();
  answer_init();
};

void Mine_sleeper::run()
{
  /* once */
  std::cout << "________problem\n";
  print_board();
  std::system("stty -icanon");
  Point now_pos{0,0};
  get_x(now_pos) = 0;get_y(now_pos) = 0;

  char ch;
  std::cin >> ch;
  while(ch != 'q') {
    std::cout << "\nhはひだり, jはした, kはうえ, lはみぎ, fははたをたてる, dはそのばをひらく\n";
    if(ch == 'h')--get_x(now_pos);
    else if(ch == 'j')++get_y(now_pos);
    else if(ch == 'k')--get_y(now_pos);
    else if(ch == 'l')++get_x(now_pos);
    else if(ch == 'f')
    {
      board[get_y(now_pos)][get_x(now_pos)] = "!";
    }
    else if(ch == 'd') {
      if(board[get_y(now_pos)][get_x(now_pos)] == "!") {
        std::cout << "thats break? -Y?";
        std::cin >> ch;
        if(ch != 'y' && ch != 'Y')continue;
      }
      board[get_y(now_pos)][get_x(now_pos)] = answer_Board[get_y(now_pos)][get_x(now_pos)];
      if(board[get_y(now_pos)][get_x(now_pos)] == "*") {
        std::cout << '\n';
        print_board();
        return;
      } else if(board[get_y(now_pos)][get_x(now_pos)] == "0") {
        board_cover(now_pos);
      }
    }

    if(8 < get_x(now_pos))get_x(now_pos) = 8;
    if(get_x(now_pos) < 0)get_x(now_pos) = 0;
    if(get_y(now_pos) < 0)get_y(now_pos) = 0;
    if(8 < get_y(now_pos))get_y(now_pos) = 8;

    std::cout << '\n';
    print_board(now_pos);
    if(check_board()) {
      return;
    }
    std::cin >> ch;
  }
};

void Mine_sleeper::print_result()
{
  if (check_board()) {
    winner();
  } else {
    failure();
  }
  std::cout << "___________answer\n";
  for (auto& e : answer_Board) {
    for (auto& f : e) {
      std::cout << f << ' ';
    }
    std::cout << '\n';
  }
};
Point operator+(const Point& pos1, const Point& pos2)
{
  return {pos1.first + pos2.first, pos1.second + pos2.second};
};
int& Mine_sleeper::get_x(Point& value)
{
  return value.first;
};
int& Mine_sleeper::get_y(Point& value)
{
  return value.second;
};

void Mine_sleeper::print_board()
{
  for(const auto& e : board) {
    for(const auto& f : e) {
      std::cout << f << ' ';
    }
    std::cout << '\n';
  }
};
void Mine_sleeper::print_board(Point pos)
{
  for(int i = 0;i < 9;++i)
  {
    for(int j = 0;j < 9;++j)
    {
      if(i == get_y(pos) && j == get_x(pos))std::cout << "□ ";
      else std::cout << board.at(i).at(j) << ' ';
    }
    std::cout << '\n';
  }
};

std::bitset<8> Mine_sleeper::available_dic(Point pos)
{
  std::bitset<8> available_use("11111111");
  /*
     012
     3*4
     567
   */
  if(get_x(pos) == 0) {
    available_use[0] = available_use[3] = available_use[5] = false;
  } else if(get_x(pos) == 8) {
    available_use[2] = available_use[4] = available_use[7] = false;
  }
  if(get_y(pos) == 0) {
    available_use[0] = available_use[1] = available_use[2] = false;
  } else if(get_y(pos) == 8) {
    available_use[5] = available_use[6] = available_use[7] = false;
  }
  return available_use;
};

int Mine_sleeper::check_pos_count(const Point& pos)
{
  std::bitset<8> available_use = available_dic(pos);
  /*
     012
     3*4
     567
   */
  auto count = 0;
  for(auto i = 0;i < 8;++i) {
    if(available_use[i]) {
      Point new_pos{pos + dir[i]};
      if(answer_Board[get_y(new_pos)][get_x(new_pos)] == '*')++count;
    }
  }
  return count;
};

void Mine_sleeper::board_cover(Point pos)
{
  /*
     012
     3*4
     567
   */
  std::bitset<8> available_use = available_dic(pos);
  for(auto i = 0;i < 8;++i) {
    if(available_use[i]) {
      Point new_pos{pos + dir.at(i)};
      if( board[get_y(new_pos)][get_x(new_pos)].size() > 2 ) {
        if((board[get_y(new_pos)][get_x(new_pos)] = answer_Board[get_y(new_pos)][get_x(new_pos)]) == "0") {
          board_cover(new_pos);
        }
      }
    }
  }
};

bool Mine_sleeper::check_board()
{
  auto bom = 0;
  for(const auto& e : board) {
    for(const auto& f : e) {
      if(f == "!") {
        ++bom;
      }
      else if(f.size() > 1)return false;
    }
  }
  if(bom > 10)return false;
  return true;
};

void Mine_sleeper::winner()
{
  std::cout << "you clear ~~(∵)~\n";
};
void Mine_sleeper::failure()
{
  std::cout << "you miss ~~(^△ ^)~\n";
};


void Mine_sleeper::bom_pos_init()
{
  for(int i = 0;i < 10;++i)
  {
    Point pos;
    get_x(pos) = (rng() % 9);
    get_y(pos) = (rng() % 9);
    bool find = false;
    for(const auto& e : bom_pos) {
      if(e == pos) {
        find = true;
        break;
      }
    }
    if(!find) {
      bom_pos.push_back(pos);
    } else {
      --i;
      continue;
    }
  }
};
void Mine_sleeper::board_init()
{
  for(int i = 0;i < 10;++i) {
    answer_Board[get_y(bom_pos.at(i))][get_x(bom_pos.at(i))] = '*';
  }
};
void Mine_sleeper::answer_init()
{
  for(auto i = 0;i < 9;++i) {
    for(auto j = 0;j < 9;++j) {
      if(answer_Board.at(i).at(j) == '*')continue;
      Point pos {j,i};
      get_x(pos) = j;
      get_y(pos) = i;
      answer_Board.at(i).at(j) = check_pos_count(pos) + '0';
    }
  }
};

