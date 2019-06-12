#include <fstream>
#include <iostream>
#include <random>

class SelectDoor{
  private:
    int match_count;
    int play_count;
    std::ofstream ofs;
  public:
    SelectDoor():match_count{0},play_count{0}{};
    void init() {
      ofs.open("selectFirst.csv");
    }
    void action(int count_t) {
      std::random_device seed_gen;
      std::mt19937 target_random_engine(seed_gen());
      std::random_device seed_gen2;
      std::mt19937 player_random_engine(seed_gen2());

      std::uniform_real_distribution<> dist1(1, 4);
      std::uniform_real_distribution<> dist2(1, 4);
      /*1,2,3から扉を選択する.*/

      for (auto i = 0;i < count_t;++i) {
        ofs << this->result() << '\n';
        int r1 = dist1(target_random_engine);
        int r2 = dist2(player_random_engine);
        if (r1 == r2) {
          ++match_count;
        }
        ++play_count;
      }
    }
    double result(){
      if (play_count == 0)return 0.0;
      return static_cast<double>(match_count)/play_count;
    }
};

class SelectDoorAddInformation{
  private:
    int match_count;
    int play_count;
    std::ofstream ofs;
  public:
    SelectDoorAddInformation():match_count{0},play_count{0}{};
    void init() {
      ofs.open("selectSecond.csv");
    }
    int change(const int& t1, const int& t2) {
      if (t1 == t2) { // change is error
        return 0; // anywhere is wrong
      } else {
        return t1; // anywhere is success
      }
    }
    void action(int count_t) {
      std::random_device seed_gen;
      std::mt19937 target_random_engine(seed_gen());
      std::random_device seed_gen2;
      std::mt19937 player_random_engine(seed_gen2());

      std::uniform_real_distribution<> dist1(1, 4);
      std::uniform_real_distribution<> dist2(1, 4);
      /*1,2,3から扉を選択する.*/

      for (auto i = 0;i < count_t;++i) {
        ofs << this->result() << '\n';
        int r1 = dist1(target_random_engine);
        int r2 = dist2(player_random_engine);
        r2 = change(r1, r2);//change door
        if (r1 == r2) {
          ++match_count;
        }
        ++play_count;
      }
    }
    double result(){
      if (play_count == 0)return 0.0;
      return static_cast<double>(match_count)/play_count;
    }
};

int main(int argc, char** argv) {
  SelectDoor tmp;
  tmp.init();
  tmp.action(10000);
  std::cout << "test-start" << '\n';
  std::cout << tmp.result() << '\n';
}
