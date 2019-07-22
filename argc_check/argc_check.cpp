#include <iostream>

/*
 * argv[argc+1]の要素を持つらしい
 * argv[argc] == 0
*/

int main(int argc, char** argv) {
  std::cout << sizeof(argv) << '\n';
  //for (auto i = 0;i < argc;++i) {
  //  std::cout << i << ':' << argv[i] << '\n';
  //}
  for (auto i = 0;i <= argc;++i) {
    std::cout << i << ':' << argv[i] << '\n';
  }
  if (argv[argc] == 0) {
    std::cout << "argv[argc] == 0\n";
  } else {
    std::cout << "argv[argc] != 0\n";
  }
}
