#include <iostream>

#include <fcntl.h>
#include <unistd.h>


int main(int argc, char** argv)
{
  int first_fd = open("first_fd",O_RDONLY | O_EXCL | O_CREAT);
  int second_fd = open("second_fd",O_RDONLY | O_EXCL | O_CREAT);
  close(first_fd);
  close(second_fd);
}
