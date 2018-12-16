#ifndef Mine_sleeper_hpp
#define Mine_sleeper_hpp

#include <iostream>
#include <vector>
#include <bitset>
#include <string>
#include <utility>
#include <random>

using Point = std::pair<int, int>;
Point operator+(const Point&, const Point&);

class Mine_sleeper{
  private:
    std::vector<std::vector<std::string>> board;
    std::vector<std::vector<char>> answer_Board;
    std::vector<Point> bom_pos;

    const std::vector<Point> dir{{-1,-1},{0,-1},{1,-1},{-1,0},{1,0},{-1,1},{0,1},{1,1}};
    std::random_device rng;
    int& get_x(Point&);
    int& get_y(Point&);
    void print_board();
    void print_board(Point pos);
    std::bitset<8> available_dic(Point pos);
    int check_pos_count(const Point&);//init()
    void board_cover(Point);//0の場合
    void bom_pos_init();
    void board_init();
    void answer_init();
    bool check_board();

    void winner();
    void failure();
  public:
    Mine_sleeper();
    ~Mine_sleeper();

    void init();
    void run();
    void print_result();
};
#endif
