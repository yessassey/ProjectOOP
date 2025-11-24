#ifndef PHONEBOOKMANAGER_H
#define PHONEBOOKMANAGER_H

#include <vector>
#include <string>
#include "Person.h"

class PhonebookManager {
private:
    std::vector<Person> contacts;

public:
    void addContact();
    void editContact();
    void deleteContact();
    void viewContacts();
    void searchContact();
    void loadFromFile(const std::string &filename);
    void saveToFile(const std::string &filename);
};

#endif