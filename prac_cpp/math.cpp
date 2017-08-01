#include "math.h"
using namespace std;
int main(){
  double value = cos(3.141592); //余弦を求める
  value = acos(0.5); //逆余弦を求める
  value = fmax(1.3,2); //最大値を求める
  value = pow(2,3); //累乗を求める ここでは2の3乗で8
  copysign(-5,value); //valueの絶対値に-5の符号をつける
  return 0;
}

