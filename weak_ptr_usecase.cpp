#include <iostream>
#include <memory>
 
using namespace std;
 
class Dog {
 
 private:
  weak_ptr<Dog> _pFriend;
  std::string _name;
 
 public:
  Dog(const std::string& iName) : _name(iName) { cout << "Dog [" << _name << "] is created!\n"; }
  ~Dog() { cout << "Dog [" << _name << "] is destroyed!\n"; }
 
  void bark() { cout << "I am dog : " << _name << endl; }
  void makeFriend(shared_ptr<Dog>& iFrnd) { _pFriend = iFrnd; }
 
  void showFriend() {
    if(!_pFriend.expired()) { // without this check lock will throw exception.
      cout << "My friend is : " << _pFriend.lock()->_name << endl;
	  cout << "And he is owned by : " << _pFriend.use_count() << " pointers.\n";
	}
  }
};
 
int main() {
	shared_ptr<Dog> dog1(new Dog("Rocket"));
	shared_ptr<Dog> dog2(new Dog("Groot"));
 
	dog1->makeFriend(dog2);
	dog2->makeFriend(dog1);
 
	dog1->showFriend();
 
	return 0;
}
