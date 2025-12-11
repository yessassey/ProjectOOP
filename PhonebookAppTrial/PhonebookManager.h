#ifndef PHONEBOOKMANAGER_H
#define PHONEBOOKMANAGER_H

#include <vector>
#include <string>
#include "Person.h"
using namespace std;

class PhonebookManager
{
private:
    vector<Person> contacts;

public:
    void addContact();
    void editContact();
    void deleteContact();
    void viewContacts();
    void searchContact();
    void loadFromFile(const string &filename);
    void saveToFile(const string &filename);
    void sortContactsByName();
};

#endif