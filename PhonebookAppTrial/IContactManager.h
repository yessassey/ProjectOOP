#ifndef ICONTACTMANAGER_H
#define ICONTACTMANAGER_H

#include "Person.h"
#include <vector>
#include <string>

using namespace std;

class IContactManager
{
public:
    virtual void addContact(const Person &p) = 0;
    virtual void editContact(int index, const Person &p) = 0;
    virtual void deleteContact(int index) = 0;

    virtual vector<Person> &getContacts() = 0;

    virtual void loadFromFile(const string &filename) = 0;
    virtual void saveToFile(const string &filename) = 0;

    virtual ~IContactManager() {}
};

#endif
