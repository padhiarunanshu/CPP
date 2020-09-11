// Q: what is the order of execution of new, c'tor, d'tor and delete in cpp
#include <iostream>
using namespace std;

class A {
  public:
	A() {
		cout << "A::A()\n";
	}
	void* operator new(size_t size) {
		cout << "Overloaded operator new [size = " << size << "]\n"; 
        return NULL;
	}
	
	~A() {
		cout << "A::~A()\n";
	}
	void operator delete(void* p) {
        cout<< "Overloaded operator delete" << endl;
	}
};

// ----------------------------------------------------------------------
// Q: Design final class in c++ 

class Final;
class MakeFinal {
    private:
        MakeFinal() {}

        friend class Final;
};

class Final : virtual public MakeFinal {
    public:
        Final() {}
};

class Derived : public Final {};

// **************************************************************************************** //
int main() {

    // 01. test
	A* p = new A();
	delete p;
	
    // 02. test
    Derived d; // compiler error
    Final f; // ok

	return 0;
}

