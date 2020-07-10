// auto_ptr impl

template<class T>
class auto_ptr
{
public:
	explicit auto_ptr(T* p = 0) : pointee(p) {}
	~auto_ptr() { delete pointee; }

	template<class U>
	auto_ptr(auto_ptr<U>& rhs) : pointee(rhs.release()) {}

	template<class U>
	auto_ptr<T>& operator=(auto_ptr<U>& rhs) {
		if (this != &rhs) {
			reset(rhs.release());
		}
		return *this;
	}

	T& operator*() const { return *pointee; }
	T* operator->() const { return pointee; }
	T* get() const { return pointee; }
	
	T* release() {
		T* oldPointee = pointee;
		pointee = 0;
		return oldPointee;
	}

	void reset(T* p = 0) {
		delete pointee;
		pointee = p;
	}

private:
	T* pointee;
};

// --------------------------------------------------
// my implementation

#include <iostream>
#include <cstring>
using namespace std;

template<typename T>
class auto_ptr {
 public:
  explicit auto_ptr(T* ptr) : pointee(ptr) {}
  ~auto_ptr() { delete pointee; }
  
  auto_ptr(auto_ptr<T>& rhs);
  auto_ptr<T>& operator=(auto_ptr<T>& rhs);
  
  T& operator*() const { return *pointee; };
  T* operator->() const { return pointee; };
  
  T* release();
  void reset(T* p = 0);

 private:
  T* pointee;
};

template<typename T>
auto_ptr<T>::auto_ptr(auto_ptr<T>& rhs) {
  pointee = rhs.pointee;
  rhs.pointee = 0;
}

template<typename T>
auto_ptr<T>& auto_ptr<T>::operator=(auto_ptr<T>& rhs) {
  if(this == &rhs) return *this;
  
  delete pointee;
  pointee = rhs.pointee;
  rhs.pointee = 0;

  return *this;
}

T* auto_ptr<T>::release() {
  T* old = pointee;
  pointee = 0;
  return old;
}

void auto_ptr<T>::reset(T* p = 0) {
  delete pointee;
  pointee = p;
}

// class to be wrapped in auto_ptr
class A {
  char* ptr;
 public:
   A() {
     ptr = new char[1];
     *ptr = '\0';
   }
   
   A(const char* p) {
   	 size_t len = strlen(p);
   	 
   	 ptr = new char[len+1];
   	 memcpy(ptr, p, len+1);
   	 
   }
   
   void display() {
   	 cout << "display, ptr = " << *ptr;
   }
   
   ~A() {
   	 delete[] ptr;
   }
};

// write client code
int main() {
	// auto_ptr<A> p = ;
	
	return 0;
}





