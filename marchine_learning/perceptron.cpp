#include <iostream>
#include <vector>

float dot(const std::vector<float>& v1, const std::vector<float>& v2)
{
  float sum{0}; 
  for (auto i = 0;i < v1.size();++i) {
    sum += v1[i]*v2[i];
  }
  return sum;
}

float step(const float& v)
{
  return (v > 0)?1:0;
}

float forward(const std::vector<float>& v1, const std::vector<float>& v2)
{
  float u = dot(v1, v2);
  return step(u);
}

void train(std::vector<float>& v1, const std::vector<float>& v2, const float& t, const float& e)
{
  float z = forward(v1, v2);
  for (auto i = 0;i < v1.size();++i) {
    v1[i] += (t - z)*v2[i]*e;
  }
}

namespace Data{
  const int DATA_NUMS = 4;
  const int WEIGH_NUMS = 3;
};

int main(int argc, char** argv)
{
  //学習率
  const float e = 0.1;

  //入力データ
  std::vector<std::vector<float>> x 
  {{1,0,0},{1,0,1},{1,0,1},{1,1,1}};

  //論理積
  std::vector<float> t{0,0,0,1};

  //論理和
  //std::vector<float> t{0,1,1,1};

  //重みをゼロで初期化
  std::vector<float> w{0,0,0};

  int epoch = 10;
  for (auto i = 0;i < epoch;++i) {
    std::cout << "epoch:" << i << ' ';
    for (auto j = 0;j < Data::DATA_NUMS;++j) {
      train(w,x[j],t[j],e);
    }
    for (auto j = 0;j < Data::WEIGH_NUMS;++j) {
      std::cout << "w" << j << ':' << w[j] << ' ';
    }
    std::cout << '\n';
  }

  for (auto i = 0;i < Data::DATA_NUMS;++i) {
    std::cout << forward(x[i],w);
  }
  std::cout << '\n';
}
