#include <iostream>
#include <fstream>

int main(int argc, char** argv) {
  std::ifstream ifs;
  ifs.open("filename.txt");
  if (ifs) {
    std::cerr << "cerr ifs open\n";
  }
  int a;
  ifs >> a;
  std::cout << a << '\n';
}
