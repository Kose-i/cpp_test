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

#define die(str) do{perror(str);exit(EXIT_FAILURE);}while(0)

int main(int argc, char** argv) {
  int ui_fd = open("/dev/uinput",O_WRONLY | O_NONBLOCK);
  if (ui_fd < 0) die("error :open");

  if(ioctl(ui_fd, UI_SET_EVBIT,EV_REL) < 0) die("error :iotrl");
  if(ioctl(ui_fd, UI_SET_RELBIT,REL_X) < 0) die("error :iotrl");
  if(ioctl(ui_fd, UI_SET_RELBIT,REL_Y) < 0) die("error :iotrl");

  if(ioctl(ui_fd, UI_SET_EVBIT,EV_KEY) < 0) die("error :iotrl");
  if(ioctl(ui_fd, UI_SET_KEYBIT,BTN_LEFT) < 0) die("error :iotrl");

  struct uinput_user_dev uidev;
  memset(&uidev, 0, sizeof(uidev));
  snprintf(uidev.name, UINPUT_MAX_NAME_SIZE,"uinput-sample");
  uidev.id.bustype = BUS_USB;
  uidev.id.vendor = 0x1;
  uidev.id.product = 0x1;
  uidev.id.version = 1;

  if (write(ui_fd, &uidev, sizeof(uidev)) < 0)die("error :write");

  if (ioctl(ui_fd, UI_DEV_CREATE) < 0)die("error :ioctl");

  sleep(2);

  //srand(time(NULL));

  while (1) {
    int mouse_event = 1;//1押されている時0押されていない時

    for (int i = 0;i < 20;++i) {
      struct input_event ev;
      if (i % 2 == 0) {
        mouse_event = 1;
        memset(&ev, 0, sizeof(struct input_event));
        ev.type = EV_KEY;
        ev.code = BTN_LEFT;
      ev.value = mouse_event;
      if (write(ui_fd, &ev, sizeof(struct input_event)) < 0)die("error :write");
      } else {

      usleep(15000);
      mouse_event = 0;

      memset(&ev, 0, sizeof(struct input_event));
      ev.type = EV_KEY;
      ev.code = BTN_LEFT;
      ev.value = mouse_event;
      if (write(ui_fd, &ev, sizeof(struct input_event)) < 0)die("error :write");
      }

      memset(&ev, 0, sizeof(struct input_event));
      ev.type = EV_SYN;
      ev.code = 0;
      ev.value = 0;
      if (write(ui_fd, &ev, sizeof(struct input_event)) < 0)die("error :write");
    }
    //sleep(500000);
  }

  sleep(2);

  if (ioctl(ui_fd, UI_DEV_DESTROY) < 0 ) die("error :ioctl");

  close(ui_fd);

  return 0;
}
