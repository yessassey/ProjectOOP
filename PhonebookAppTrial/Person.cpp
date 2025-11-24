#include "Person.h"

Person::Person(std::string n, std::string p, std::string a)
    : name(n), phone(p), address(a) {}

void Person::setName(const std::string &n) { name = n; }
void Person::setPhone(const std::string &p) { phone = p; }
void Person::setAddress(const std::string &a) { address = a; }

std::string Person::getName() const { return name; }
std::string Person::getPhone() const { return phone; }
std::string Person::getAddress() const { return address; }

void Person::print() const {
    std::cout << "Name: " << name << "\nPhone: " << phone << "\nAddress: " << address << "\n";
}