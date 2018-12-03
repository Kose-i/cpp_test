#include <iostream>

class A{
  public:
    A(){std::cout << "A constructor\n";};
};

class B:public A
{
  public:
    B(){std::cout << "B constructor\n";};
    B(int){std::cout << "B constructor (int)\n";};
};
int main(){
  B a(2);
  B c;
}
