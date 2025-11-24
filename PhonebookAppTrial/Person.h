#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person {
private:
    std::string name;
    std::string phone;
    std::string address;

public:
    Person(std::string n = "", std::string p = "", std::string a = "");

    void setName(const std::string &n);
    void setPhone(const std::string &p);
    void setAddress(const std::string &a);

    std::string getName() const;
    std::string getPhone() const;
    std::string getAddress() const;

    void print() const;
};

#endif