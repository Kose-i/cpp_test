class my_time{
  public:
    my_time(){
      struct tm now_time;
      time_t t = time_t(NULL);
      localtime_r(&t, &now_time);
      std::cout << now_time.tm_hour<<  now_time.tm_min << now_time.tm_sec << "initialized\n";
      this->hour = now_time.tm_hour;
      this->minutes = now_time.tm_min;
      this->seconds = now_time.tm_sec;
    };
    my_time(int h, int m = 0, int s = 0):hour(h), minutes(m), seconds(s){};
    friend bool operator==(const class my_time& e ,const class my_time& t){
      return (t.hour == e.hour && t.minutes == e.minutes && t.seconds == e.seconds);
    }
    void set_refectaling() {
      while (this->seconds > 60) {
        this->seconds -= 60;
        ++this->minutes;
      }
      while (this->minutes > 60) {
        this->minutes -= 60;
        ++this->hour;
      }
      while (this->hour >= 24)this->hour-=24;
    }
    void go_seconds(int seconds) {
      this->seconds+=seconds;
      set_refectaling();
    }
    void go_minutes(int minutes) {
      this->seconds+=seconds;
      set_refectaling();
    }
    void go_hours(int hours) {
      this->seconds+=seconds;
      set_refectaling();
    }
    void output() {
      std::cout  \
      << std::setfill('0') << std::setw(2) << this->hour << ':' \
      << std::setfill('0') << std::setw(2) << this-> minutes << '.'\
      << std::setfill('0') << std::setw(2) << this->seconds << '\n';
    }
  private:
    int hour;
    int minutes;
    int seconds;
};
