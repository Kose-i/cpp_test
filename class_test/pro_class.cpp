#include <iostream>

class A{
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
}
