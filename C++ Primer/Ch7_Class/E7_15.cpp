#include <iostream>

struct Person{
  std::string name;
  std::string address;
  Person() = default;
  Person(const std::string sname, const std::string saddr):name(sname)
							  ,address(saddr)
  {}
  Person(std::istream& is){read(is,*this);}
};


std::istream& read(std::istream& is, Person &person){
  return is >> person.name >> person.address;
}

std::ostream& print(std::ostream& os, const Person &person){
  return os << person.name << " " << person.address;
} 
