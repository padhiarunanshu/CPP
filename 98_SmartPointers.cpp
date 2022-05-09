#include <iostream>

using namespace std;

// sample Smart pointer class e.g. 
template<class T>
class SmartPtr {
  public:
    explicit SmartPtr(T* ptr) : _pointee(ptr) {}
    SmartPtr& operator=(const SmartPtr& rhs);
    ~SmartPtr() {}

    T* operator->() const {
      //..
      return *_pointee;
    }

    T& operator*() {
        // ..
        return _pointee;
    }

  private:
    T* _pointee;
};

// if written outside class..
// template<class T>
// T& SmartPtr<T>::operator*() {
//   // ..
//   return _pointee;
// }


