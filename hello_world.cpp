#include <iostream>
#include <string>
#include <thread>
#include <chrono>

const std::string hello_world{"hello world"};

int main(int argc, char** argv) {
  for (auto it = hello_world.begin();it != hello_world.end();++it) {
    for (auto c = 'a';c != 'z' + 1;++c) {
      std::cout << c;
      std::this_thread::sleep_for(std::chrono::milliseconds(10));
      std::cout << '\b';
    }
    std::cout << *it;
  }
  std::cout << '\n';
}
