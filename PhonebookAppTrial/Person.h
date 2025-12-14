#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

using namespace std;

class Person
{
private:
    string name;
    string nickname;
    string phone;
    string email;
    string address;

public:
    Person(string n = "", string nn = "", string p = "", string e = "", string a = "");

    void setName(const string &n);
    void setNickname(const string &nn);
    void setPhone(const string &p);
    void setEmail(const string &e);
    void setAddress(const string &a);

    string getName() const;
    string getNickname() const;
    string getPhone() const;
    string getEmail() const;
    string getAddress() const;

    void print() const;
};

#endif