#include <iostream>
#include <map>

int main(int argc, char** argv) {
  std::map<char,int> tmp;
  tmp.insert(std::make_pair('a',0));
  tmp.insert(std::make_pair('b',1));
  tmp.insert(std::make_pair('c',2));
  std::cout << tmp['d'] << '\n';
  tmp['e'] = 8;
  std::cout << tmp['e'] << '\n';
}
