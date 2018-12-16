#ifndef Mine_sleeper_hpp
#define Mine_sleeper_hpp
#include <iostream>
#include <vector>
#include <bitset>
#include <string>
#include <utility>
#include <random>
class Mine_sleeper{
  using Point = std::pair<int, int>;
  private:
    const std::vector<Point> dir{{-1,-1},{0,-1},{1,-1},{-1,0},{1,0},{-1,1},{0,1},{1,1}};
    Point operator+(const Point&, const Point&)
    int& get_x(Point&);
    int& get_y(Point&);
    void print();
  public:
    Mine_sleeper();
    ~Mine_sleeper();

    void init();
    void run();
    void print_result();
}
#endif
