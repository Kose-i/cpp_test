#include "mouse_set.hpp"
/*
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
*/

#define die(str) do{perror(str);exit(EXIT_FAILURE);}while(0)

Mouse_setup::Mouse_setup(){}
void Mouse_setup::initialize()
{
  ui_fd = open("/dev/uinput",O_WRONLY | O_NONBLOCK);
  if (ui_fd < 0) die("error :open");

  if(ioctl(ui_fd, UI_SET_EVBIT,EV_REL) < 0) die("error :iotrl");
  if(ioctl(ui_fd, UI_SET_RELBIT,REL_X) < 0) die("error :iotrl");
  if(ioctl(ui_fd, UI_SET_RELBIT,REL_Y) < 0) die("error :iotrl");

  if(ioctl(ui_fd, UI_SET_EVBIT,EV_KEY) < 0) die("error :iotrl");
  if(ioctl(ui_fd, UI_SET_KEYBIT,BTN_LEFT) < 0) die("error :iotrl");

  memset(&uidev, 0, sizeof(uidev));
  snprintf(uidev.name, UINPUT_MAX_NAME_SIZE,"uinput-sample");
  uidev.id.bustype = BUS_USB;
  uidev.id.vendor = 0x1;
  uidev.id.product = 0x1;
  uidev.id.version = 1;

  if (write(ui_fd, &uidev, sizeof(uidev)) < 0)die("error :write");

  if (ioctl(ui_fd, UI_DEV_CREATE) < 0)die("error :ioctl");

}

Mouse_setup::~Mouse_setup(){
  if (ioctl(ui_fd, UI_DEV_DESTROY) < 0 ) die("error :ioctl");

  close(ui_fd);
}

void Mouse_setup::drag()const{
//  push_bottom();
}

void Mouse_setup::click()const{
}

void Mouse_setup::double_click()const{
}

void Mouse_setup::push_bottom(){
}

void Mouse_setup::pull_bottom(){
}

void Mouse_setup::move_cursor(){
}
