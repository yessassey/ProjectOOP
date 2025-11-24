#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person
{
private:
    std::string name;
    std::string nickname;
    std::string phone;
    std::string email;
    std::string address;

public:
    Person(std::string n = "", std::string nn = "", std::string p = "", std::string e = "", std::string a = "");

    void setName(const std::string &n);
    void setNickname(const std::string &nn);
    void setPhone(const std::string &p);
    void setEmail(const std::string &e);
    void setAddress(const std::string &a);

    std::string getName() const;
    std::string getNickname() const;
    std::string getPhone() const;
    std::string getEmail() const;
    std::string getAddress() const;

    void print() const;
};

#endif