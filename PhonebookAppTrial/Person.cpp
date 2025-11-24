#include "Person.h"

Person::Person(std::string n, std::string nn, std::string p, std::string e, std::string a)
    : name(n), nickname(nn), phone(p), email(e), address(a) {}

void Person::setName(const std::string &n) { name = n; }
void Person::setNickname(const std::string &nn) { nickname = nn; }
void Person::setPhone(const std::string &p) { phone = p; }
void Person::setEmail(const std::string &e) { email = e; }
void Person::setAddress(const std::string &a) { address = a; }

std::string Person::getName() const { return name; }
std::string Person::getNickname() const { return nickname; }
std::string Person::getPhone() const { return phone; }
std::string Person::getEmail() const { return email; }
std::string Person::getAddress() const { return address; }

void Person::print() const
{
    std::cout << "Name: " << name
              << "\nNickname: " << nickname
              << "\nPhone: " << phone
              << "\nEmail: " << email
              << "\nAddress: " << address << "\n";
}