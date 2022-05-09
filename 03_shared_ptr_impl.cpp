#ifndef SHARED_PTR_CUSTOM_H_INCLUDED
#define SHARED_PTR_CUSTOM_H_INCLUDED

// shared_ptr.h
template<typename T>
class sharedPtr {

public:
    sharedPtr(T* iData = nullptr);
    sharedPtr(const sharedPtr<T>& irhs);
    sharedPtr operator=(const sharedPtr<T>& irhs);
    ~sharedPtr();
    T* operator->();
    T operator*();
    int refCount() {
        return *_refCount;
    }
private:
    void destroy();
    T* _data;
    int* _refCount;

};
extern template class sharedPtr<int>;

#endif // SHARED_PTR_CUSTOM_H_INCLUDED


// shared_ptr.cpp
#include "shared_ptr.h"

using namespace std;

template <typename T>
sharedPtr<T>::sharedPtr(T* iData) {
    cout<<"Constructor"<<endl;
    _data = iData;
    _refCount = new int(1);
}

template <typename T>
sharedPtr<T>::sharedPtr(const sharedPtr<T>& irhs) {
    cout<<"Copy Constructor"<<endl;
    _data = irhs._data;
    _refCount = irhs._refCount;
    (*_refCount)++;
}

template <typename T>
sharedPtr<T> sharedPtr<T>::operator=(const sharedPtr<T>& irhs) {
    cout<<"assignment operator"<<endl;
    if (this != &irhs) {
        destroy();
        _data = irhs._data;
        _refCount = irhs._refCount;
        (*_refCount)++;
    }
    return *this;
}

template <typename T>
sharedPtr<T>::~sharedPtr() {
    destroy();
}
template <typename T>
T* sharedPtr<T>::operator->() {
    if(this->_data)
        return _data;
    else
        return nullptr;
}

template <typename T>
T sharedPtr<T>::operator*() {
    return *_data;
}

template <typename T>
void sharedPtr<T>::destroy() {
    cout<<"Destroying"<<endl;
    if (*_refCount==1) {
        cout<<"last object being destroyed"<<endl;
        delete _data;
        delete _refCount;
    } else {
        cout<<"Not last object"<<endl;
        --(*_refCount);
    }
}

template class sharedPtr<int>;

    /*
    sharedPtr<int> s1(new int(5));
    sharedPtr<int> s2(new int(3));
    sharedPtr<int> s3 = s1;
    cout<<"s2 count "<<s2.refCount()<<endl;
    cout<<"s2 data "<<*s2<<endl;
    cout<<"s3 count "<<s3.refCount()<<endl;
    cout<<"s3 data "<<*s3<<endl;
    s2=s1; // s1 = s2 = ref = 3
	s3=s2;
    cout<<"count "<<s2.refCount()<<endl;
    cout<<"data "<<*s2<<endl;
    */
