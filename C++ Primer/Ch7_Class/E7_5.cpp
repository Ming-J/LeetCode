#include <iostream>

struct Person{
  std::string name;
  std::string address;

  std::string getName() const{
    return name;
  }
  std::string getAddress() const{
    return address;
  }
}

/*
  The function should be const, since we will not modify the this object.
  We are simply just getting the member function.
  
  If we have a const Person, he can only call member functions with
  the same constness. If the member functions are declares to be
  const, both a const Person and a person can utilise. Having const
  member functions effective increases their flexibility.

*/
