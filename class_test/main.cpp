#include <iostream>

class A{
  public:
    A(){}
    A(const int&)
    {
      std::cout << "A constructor A(int)\n";
    }
  protected:
    void protect_test(){
      std::cout << "A class protect_test()\n";
    };
  private:
    void test(){
      std::cout << "A class test()\n";
    };
};

class B: public A
{
  public:

    B(){}
    B(const int& a):A(a){}

    void test(){
      std::cout << "B class test()\n";
    }
    void protect_test(){
      std::cout << "B class protect_test()\n";
    }
};

int main(int argc, char** argv){
  B a;
  a.test();
  B b(3);
}
