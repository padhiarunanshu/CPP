#include <bits/stdc++.h>
using namespace std;

// Compile 1
class Base {
  public:
    virtual void fun() {
        cout << "Base::fun()\n";
    }
};

class Derived : public Base {
  public:
    void foo() {
        cout << "Derived::foo()\n";
    }
};

// size of class that contains a string
class Widget {
  std::string s;
  public:
    void doSomething(int i) {

    }
  private:
    void doSomething(double d) {

    }
    
};

template<int val>
void addVal(int i) {
  std::cout << val + i;
}

int main() {
    // Widget d;
    // cout << sizeof(d); 
    // d.doSomething(1);
    // const int x = 2;
    // addVal<x>(3);

    return 0;
}