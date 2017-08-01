#include <random>
#include <iostream>
using namespace std;
int main()
{
  random_device rnd;
  for (int i = 0; i < 10; i++) {
    cout << rnd()/4294967295.0 << endl;
  }
  return 0;
}
