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

#include <sys/ioctl.h>
#include <fcntl.h>

int main(int argc, char** argv)
{
  display_bit(O_RDONLY);
  display_bit(O_WRONLY);
  display_bit(O_RDWR);
  //display_bit(O_EXEC);
  display_bit(O_NONBLOCK);
  display_bit(O_APPEND);
  display_bit(O_CREAT);
  display_bit(O_TRUNC);
  display_bit(O_EXCL);
  //display_bit(O_EXLOCK);
  display_bit(O_DIRECT);
  display_bit(O_FSYNC);
  display_bit(O_SYNC);
  display_bit(O_NOFOLLOW);
  display_bit(O_NOCTTY);
  //display_bit(O_TTY_INIT);
  display_bit(O_DIRECTORY);
  display_bit(O_CLOEXEC);
  display_bit(O_TMPFILE);
}
