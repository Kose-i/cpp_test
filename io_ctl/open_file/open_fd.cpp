#include <iostream>

#include <fcntl.h>
#include <unistd.h>


int main(int argc, char** argv)
{
  int first_fd = open("first_fd",O_RWONLY | O_EXCL | O_CREAT);
  int second_fd = open("second_fd",O_RWONLY | O_EXCL | O_CREAT);
  std::cout << "first_fd:" << first_fd << '\n';
  std::cout << "second_fd:" << second_fd << '\n';
  close(first_fd);
  close(second_fd);
}
