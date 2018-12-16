#include "minesleeper.hpp"
#include <iostream>
int main(int argc, char** argv)
{
  try{
    Minesleeper board;
    board.init();
    board.run();
    board.print_result();
  } catch(...) {
    std::cout << "error happen\n";
    return -1;
  }
  return 0;
}
