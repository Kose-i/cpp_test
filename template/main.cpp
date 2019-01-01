#include <iostream>

template<typename T1>
void print(const T1& print_target)
{
  std::cout << print_target << '\n';
}
void print(const int& print_target)
{
  std::cout << "int:" << print_target << '\n';
}

int main(int argc, char** argv)
{
  std::string str{"str"};
  print(str);
  auto temp = 2;
  print(temp);
}
