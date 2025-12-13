#include "Person.h"

using namespace std;

Person::Person(string n, string nn, string p, string e, string a)
    : name(n), nickname(nn), phone(p), email(e), address(a) {}

void Person::setName(const string &n) { name = n; }
void Person::setNickname(const string &nn) { nickname = nn; }
void Person::setPhone(const string &p) { phone = p; }
void Person::setEmail(const string &e) { email = e; }
void Person::setAddress(const string &a) { address = a; }

string Person::getName() const { return name; }
string Person::getNickname() const { return nickname; }
string Person::getPhone() const { return phone; }
string Person::getEmail() const { return email; }
string Person::getAddress() const { return address; }

void Person::print() const
{
    cout << "Name: " << name << "\n"
         << "Nickname: " << nickname << "\n"
         << "Phone: " << phone << "\n"
         << "Email: " << email << "\n"
         << "Address: " << address << "\n";
}