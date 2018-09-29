#ifndef My_time
#define My_time

class My_time{
  public:
    My_time();
    My_time(int h, int m = 0, int s = 0);
    My_time(const My_time&);
    ~My_time();
    //friend bool operator==(const My_time& e, const My_time& f);
    void set_refactaling();
    void go_seconds(int s);
    void go_minutes(int m);
    void go_hours(int h);
    void output()const;
  private:
    int hour;
    int minute;
    int second;
};
#endif
