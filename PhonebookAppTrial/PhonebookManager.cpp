#include "PhonebookManager.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

// gui methods
void PhonebookManager::addContact(const Person &p)
{
    contacts.push_back(p);
    sortContactsByName();
}

void PhonebookManager::editContact(int index, const Person &p)
{
    if (index >= 0 && index < (int)contacts.size())
    {
        contacts[index] = p;
        sortContactsByName();
    }
}

void PhonebookManager::deleteContact(int index)
{
    if (index >= 0 && index < (int)contacts.size())
    {
        contacts.erase(contacts.begin() + index);
        sortContactsByName();
    }
}

// original methods from console
void PhonebookManager::addContact()
{
    string name, nickname, phone, email, address;
    cin.ignore();
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter nickname: ";
    getline(cin, nickname);
    cout << "Enter phone: ";
    getline(cin, phone);
    cout << "Enter email: ";
    getline(cin, email);
    cout << "Enter address: ";
    getline(cin, address);

    contacts.push_back(Person(name, nickname, phone, email, address));
    sortContactsByName();
    cout << "Contact added successfully!\n";
}

void PhonebookManager::editContact()
{
    viewContacts();
    if (contacts.empty())
        return;

    int index;
    cout << "Enter contact number to edit: ";
    cin >> index;
    cin.ignore();

    if (index < 1 || index > (int)contacts.size())
    {
        cout << "Invalid index!\n";
        return;
    }

    string name, nickname, phone, email, address;
    cout << "Enter new name: ";
    getline(cin, name);
    cout << "Enter new nickname: ";
    getline(cin, nickname);
    cout << "Enter new phone: ";
    getline(cin, phone);
    cout << "Enter new email: ";
    getline(cin, email);
    cout << "Enter new address: ";
    getline(cin, address);

    contacts[index - 1] = Person(name, nickname, phone, email, address);
    sortContactsByName();
    cout << "Contact updated successfully!\n";
}

void PhonebookManager::deleteContact()
{
    viewContacts();
    if (contacts.empty())
        return;

    int index;
    cout << "Enter contact number to delete: ";
    cin >> index;

    if (index < 1 || index > (int)contacts.size())
    {
        cout << "Invalid index!\n";
        return;
    }

    contacts.erase(contacts.begin() + (index - 1));
    sortContactsByName();
    cout << "Contact deleted successfully!\n";
}
// view and search contacts
void PhonebookManager::viewContacts()
{
    if (contacts.empty())
    {
        cout << "No contacts available.\n";
        return;
    }

    sortContactsByName();

    cout << "\n===== CONTACT LIST (Sorted A-Z by Name) =====\n";
    for (size_t i = 0; i < contacts.size(); ++i)
    {
        cout << i + 1 << ". ";
        contacts[i].print();
        cout << "-----------------\n";
    }
}

vector<Person> PhonebookManager::searchContact(const string &keyword)
{
    vector<Person> result;
    for (const auto &c : contacts)
    {
        if (c.getName().find(keyword) != string::npos ||
            c.getNickname().find(keyword) != string::npos ||
            c.getPhone().find(keyword) != string::npos)
        {
            result.push_back(c);
        }
    }
    return result;
}

// file i/o
void PhonebookManager::loadFromFile(const string &filename)
{
    ifstream inFile(filename, ios::binary);
    if (!inFile)
    {
        cout << "File not found.\n";
        return;
    }

    contacts.clear();
    string name, nickname, phone, email, address;
    while (getline(inFile, name) && getline(inFile, nickname) &&
           getline(inFile, phone) && getline(inFile, email) &&
           getline(inFile, address))
    {
        contacts.push_back(Person(name, nickname, phone, email, address));
    }

    inFile.close();
    sortContactsByName();
    cout << "Contacts loaded from file.\n";
}

void PhonebookManager::saveToFile(const string &filename)
{
    ofstream outFile(filename);
    for (const auto &c : contacts)
    {
        outFile << c.getName() << "\n"
                << c.getNickname() << "\n"
                << c.getPhone() << "\n"
                << c.getEmail() << "\n"
                << c.getAddress() << "\n";
    }
    outFile.close();
    cout << "Contacts saved to file.\n";
}

// sort contacts by alphabetical order
void PhonebookManager::sortContactsByName()
{
    sort(contacts.begin(), contacts.end(),
         [](const Person &a, const Person &b)
         {
             string A = a.getName();
             string B = b.getName();
             transform(A.begin(), A.end(), A.begin(), ::tolower);
             transform(B.begin(), B.end(), B.begin(), ::tolower);
             return A < B;
         });
}