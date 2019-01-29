#include <algorithm>
#include <iostream>
#include <string>

void print_target_pos(const std::string& target_str, const char& target_char)
{
  auto it = std::find(target_str.rbegin(), target_str.rend(), target_char);
  std::cout << *it;
  if (it == target_str.rbegin()) {
    std::cout << "it == target_str.rbegin()\n";
  } else if (it == target_str.rend()) {
    std::cout << "it == target_str.rend()\n";
  }
}
int main(int argc, char** argv) {
  std::string target_str{"abcdefgab"};
  char target_char{'m'};
  print_target_pos(target_str, target_char);
}
