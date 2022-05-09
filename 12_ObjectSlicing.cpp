#include <iostream>
#include <string>

using namespace std;

class Dog {
  public:
    virtual void bark() {
        cout << "I don't have a name\n";
    }
    virtual void eat() {
        cout << "I eat nothing\n";
    }
};

class Dog1 : public Dog {
  string name;
  public:
    void bark() {
        cout << "My name is : " << name << endl;
    }
    
    void eat() {
        cout << "I eat meat\n";
    }
};

int main()
{
    Dog1 d1;
    Dog d = d1;
    
    d.eat() ; // d1 is sliced, it will print dog's eat function.
    
    return 0;
}