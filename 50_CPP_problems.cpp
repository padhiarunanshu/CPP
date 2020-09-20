// Q1: what is the order of execution of new, c'tor, d'tor and delete in cpp
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
// Q2: Design final class in c++ 

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

// ----------------------------------------------------------------------
// Q3: Delete this?

class A {
  public:
	A() { cout << "A::A()\n"; }
	~A() { cout << "A::~A()\n"; }

	void fun() { // calling this function will delete this
		cout << "Delete this\n";
		delete this;
	}

	// this will prevent the program to crash if an obect is created in stack and fun is called on that.
	void operator delete(void*) {
		cout << "operator delete\n";
		return ;
	}
};

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

