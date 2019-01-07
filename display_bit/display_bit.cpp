#include <iostream>

template<typename T>
void display_bit(const T& target)
{
  T tmp = 1;
  std::string answer_str{};
  for (;tmp != 0;tmp= tmp<<1) {
    answer_str += ((target&tmp)!= 0)?"1":"0";
  }
  for (auto it = answer_str.rbegin();it != answer_str.rend();++it) {
    std::cout << *it;
  }
  std::cout << '\n';
}

int main(int argc, char** argv)
{
  int a{-2};
  display_bit(a);
}
