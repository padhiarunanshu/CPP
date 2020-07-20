// Implement vector class in c++11

#include <iostream>
#include <algorithm>

using namespace std;

class vector {

 private:
  int* _data;
  size_t _size;
  
 public:
  vector() : _data(nullptr), _size(0) {}

  ~vector() { delete[] _data; }

  vector(const vector& rhs) {
  	std::cout << "copy constructor called...\n";
    _data = new int[rhs._size];
    _size = rhs._size;
    std::copy(rhs._data, rhs._data + _size, _data);
  }

  vector& operator=(const vector& rhs) {
  	std::cout << "assignment operator called...\n";
    vector copy = rhs;
    std::swap(copy, *this);
    return *this;
  }
  
  // move constructor
  vector(vector&& rhs) {
  	std::cout << "move constructor called...\n";
  	_data = std::exchange(rhs._data, nullptr);
  	_size = std::exchange(rhs._size, 0);
  }
  
  // move operator=
  vector& operator=(vector&& rhs) {
  	std::cout << "move assignment operator called...\n";
    vector copy(std::move(rhs));
    std::swap(copy, *this);
    return *this;
  }

  void push_back(int d) {
    int* newdata = new int[_size + 1];
    std::copy(_data, _data + _size, newdata);

    delete[] _data;
    _data = newdata;
    _size += 1;
    _data[_size] = d;
  }
  
  size_t size() {
  	return _size;
  }

};

vector getVector() {
	vector v;
	return v;
}

int main() {
	// your code goes here
	
	vector v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	
	vector v2 = v;
	vector v3 = std::move(v);
	
  // ToDo: check the usage of move assignment operator.
	// vector v4;
	// v4 = getVector();
	
	return 0;
}
