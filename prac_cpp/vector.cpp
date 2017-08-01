#include <stdio.h>
#include <vector>
using namespace std;
int main(){
      vector<int> vec; //vecという名前のint型の可変長配列を宣言
          vec.push_back(10); //末尾に10を追加
              vec.push_back(12); //末尾に12を追加
                  vec.pop_back(); //末尾を削除（12を削除）

                      vec.push_back(12); //末尾に12を追加
                          vec.push_back(15); //末尾に15を追加
                              for(int i=0; i<vec.size();i++){ //vecのすべての要素に繰り返し処理をする
                                        printf("%d\n",vec.at(i)); //i番目の要素を出力
                                            }
                                                vec.clear(); //要素をすべて削除
                                                    return 0;
}

