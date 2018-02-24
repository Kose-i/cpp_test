#include <iostream>
#include <vector>
#include <bitset>
#include <string>
#include <utility>
#include <random>

using Point = std::pair<int,int>;

const std::vector<Point> dir{{-1,-1},{0,-1},{1,-1},{-1,0},{1,0},{-1,1},{0,1},{1,1}};
  /*
     012
     3*4
     567
   */
Point operator+(const Point& pos1, const Point& pos2)
{
  return {pos1.first + pos2.first, pos1.second + pos2.second};
}

template<typename T>
T& get_x(std::pair<T, T>& value)
{
  return value.first;
}

template<typename T>
T& get_y(std::pair<T, T>& value)
{
  return value.second;
}

template <typename T>
void print(const std::vector<std::vector<T>>& map)
{
  for(const auto& e : map)
  {
    for(const auto& f : e)
    {
      std::cout << f << ' ';
    }
    std::cout << '\n';
  }
}

std::bitset<8> available_dic(const std::vector<std::vector<char>>& map, Point pos)
{
  std::bitset<8> available_use("11111111");
  /*
     012
     3*4
     567
   */
  if(get_x(pos) == 0)
  {
    available_use[0] = available_use[3] = available_use[5] = false;
  }
  else if(get_x(pos) == 8)
  {
    available_use[2] = available_use[4] = available_use[7] = false;
  }
  if(get_y(pos) == 0)
  {
    available_use[0] = available_use[1] = available_use[2] = false;
  }
  else if(get_y(pos) == 8)
  {
    available_use[5] = available_use[6] = available_use[7] = false;
  }
  return available_use;
}

int check_pos_count(const Point& pos, const std::vector<std::vector<char>>& map)
{
  std::bitset<8> available_use = available_dic(map ,pos);
  /*
     012
     3*4
     567
   */
  int count = 0;
  for(int i = 0;i < 8;++i)
  {
    if(available_use[i])
    {
      Point new_pos{pos + dir[i]};
      if(map[get_y(new_pos)][get_x(new_pos)] == '*')++count;
    }
  }
  return count;
}

void print_map(std::vector<std::vector<std::string>> Board, Point pos)
{
  for(int i = 0;i < 9;++i)
  {
    for(int j = 0;j < 9;++j)
    {
      if(i == get_y(pos) && j == get_x(pos))std::cout << "□ ";
      else std::cout << Board.at(i).at(j) << ' ';
    }
    std::cout << '\n';
  }
}
void Board_cover(std::vector<std::vector<std::string>>& board,const std::vector<std::vector<char>>& answer,Point& pos)
{
  /*
     012
     3*4
     567
   */
  std::bitset<8> available_use = available_dic(answer,pos);
  for(int i = 0;i < 8;++i)
  {
    if(available_use[i])
    {
      Point new_pos{pos + dir.at(i)};
      /*
      if((board[get_y(new_pos)][get_x(new_pos)] = answer[get_y(new_pos)][get_x(new_pos)]) == "0")
      {
        if( (board[get_y(new_pos)][get_x(new_pos)] == "□") )
        Board_cover(board,answer, new_pos);
        }
       */
#if 1
      {
        if( board[get_y(new_pos)][get_x(new_pos)].size() > 2 ){
          if((board[get_y(new_pos)][get_x(new_pos)] = answer[get_y(new_pos)][get_x(new_pos)]) == "0"){
            Board_cover(board,answer, new_pos);
          }
        }
      }
#endif
    }
  }
}
void failure()
{
  std::cout << "you miss ~~(^△ ^)~\n";
}
bool check_board(std::vector<std::vector<std::string>> board)
{
  int bom = 0;
  for(const auto& e : board)
  {
    for(const auto& f : e)
    {
      if(f == "!")
      {
        ++bom;
      }
      else if(f.size() > 1)return false;
    }
  }
  if(bom > 10)return false;
  return true;
}
void winner()
{
  std::cout << "you clear ~~(∵)~\n";
}
int main()
{
  std::vector<Point> bom_pos;
  std::random_device rng;
  for(int i = 0;i < 10;++i)
  {
    Point pos;
    get_x(pos) = (rng() % 9);
    get_y(pos) = (rng() % 9);
    bool find = false;
    for(const auto& e : bom_pos)
    {
      if(e == pos)
      {
        find = true;
        break;
      }
    }
    if(!find)bom_pos.push_back(pos);
    else 
    {
      --i;
      continue;
    }
  }
  std::vector<std::vector<std::string>> Board(9,std::vector<std::string>(9,"■"));
  std::vector<std::vector<char>> answer_Board(9,std::vector<char>(9,'0'));
  for(int i = 0;i < 10;++i)
  {
    answer_Board[get_y(bom_pos.at(i))][get_x(bom_pos.at(i))] = '*';
  }

  for(int i = 0;i < 9;++i)
  {
    for(int j = 0;j < 9;++j)
    {
      if(answer_Board.at(i).at(j) == '*')continue;
      Point pos {j,i};
      answer_Board.at(i).at(j) = check_pos_count(pos,answer_Board) + '0';
    }
  }

  std::cout << "________problem\n";
  print(Board);
#if 1
  std::system("stty -icanon");
  Point now_pos{0,0};
  get_x(now_pos) = 0;get_y(now_pos) = 0;
  char ch;
  std::cin >> ch;
  while(ch != 'q')
  {
    std::cout << "\nhはひだり, jはした, kはうえ, lはみぎ, fははたをたてる, dはそのばをひらく\n";
    if(ch == 'h')--get_x(now_pos);
    else if(ch == 'j')++get_y(now_pos);
    else if(ch == 'k')--get_y(now_pos);
    else if(ch == 'l')++get_x(now_pos);
    else if(ch == 'f')
    {
      Board[get_y(now_pos)][get_x(now_pos)] = "!";
    }
    else if(ch == 'd')
    {
      if(Board[get_y(now_pos)][get_x(now_pos)] == "!")
      {
        std::cout << "thats break? -Y?";
        std::cin >> ch;
        if(ch != 'y' && ch != 'Y')continue;
      }
      Board[get_y(now_pos)][get_x(now_pos)] = answer_Board[get_y(now_pos)][get_x(now_pos)];
      if(Board[get_y(now_pos)][get_x(now_pos)] == "*")
      {
        std::cout << '\n';
        print(Board);
        failure();
        print(answer_Board);
        return 0;
      }
      else if(Board[get_y(now_pos)][get_x(now_pos)] == "0")Board_cover(Board,answer_Board,now_pos);
    }

    if(8 < get_x(now_pos))get_x(now_pos) = 8;
    if(get_x(now_pos) < 0)get_x(now_pos) = 0;
    if(get_y(now_pos) < 0)get_y(now_pos) = 0;
    if(8 < get_y(now_pos))get_y(now_pos) = 8;
    std::cout << '\n';
    print_map(Board, now_pos);
    if(check_board(Board))
    {
      winner();
      print(answer_Board);
      return 0;
    }
    std::cin >> ch;
  }
#endif
  std::cout << "___________answer\n";
  print(answer_Board);
}
