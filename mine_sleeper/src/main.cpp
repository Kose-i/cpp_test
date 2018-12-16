#include "mine_sleeper.hpp"
#include <iostream>

int main(int argc, char** argv)
{
  try{
    Mine_sleeper board;
    board.init();
    board.run();
    board.print_result();
  } catch(...) {
    std::cout << "error happen\n";
    return -1;
  }
  return 0;
}
