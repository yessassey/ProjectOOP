#ifndef PHONEBOOKMANAGER_H
#define PHONEBOOKMANAGER_H

#include <vector>
#include <string>
#include "Person.h"
#include "IContactManager.h"

using namespace std;

class PhonebookManager : public IContactManager
{
private:
    vector<Person> contacts;

public:
    PhonebookManager() = default;

    // GUI-friendly methods
    void addContact(const Person &p) override;
    void editContact(int index, const Person &p) override;
    void deleteContact(int index) override;
    void loadFromFile(const string &filename) override;
    void saveToFile(const string &filename) override;

    vector<Person> &getContacts() override { return contacts; }

    // Original methods
    void addContact();  // optional: console input
    void editContact(); // optional: console input
    void deleteContact();
    void viewContacts();
    void sortContactsByName();

    vector<Person> searchContact(const string &keyword);
};

#endif
