#ifndef MOUSE_SETUP_HPP
#define MOUSE_SETUP_HPP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <linux/input.h>
#include <linux/uinput.h>

class Mouse_setup{
  private:
    int ui_fd;//uinput file district
    struct uinput_user_dev uidev;
  public:
    constexpr Mouse_setup();
    virtual ~Mouse_setup();
    void drag()const;
    void click()const;
    void double_click()const;
  private:
    void push_bottom();
    void pull_bottom();
    void move_cursor();
};

#endif
