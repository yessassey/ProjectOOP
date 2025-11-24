#include "PhonebookManager.h"
#include <iostream>
#include <fstream>
#include <algorithm>

void PhonebookManager::addContact() {
    std::string name, phone, address;
    std::cin.ignore();
    std::cout << "Enter name: ";
    std::getline(std::cin, name);
    std::cout << "Enter phone: ";
    std::getline(std::cin, phone);
    std::cout << "Enter address: ";
    std::getline(std::cin, address);

    contacts.push_back(Person(name, phone, address));
    std::cout << "Contact added successfully!\n";
}

void PhonebookManager::viewContacts() {
    if (contacts.empty()) {
        std::cout << "No contacts available.\n";
        return;
    }

    std::cout << "\n===== CONTACT LIST =====\n";
    for (size_t i = 0; i < contacts.size(); ++i) {
        std::cout << i + 1 << ". ";
        contacts[i].print();
        std::cout << "-----------------\n";
    }
}


void PhonebookManager::editContact() {
    viewContacts();
    if (contacts.empty()) return;

    int index;
    std::cout << "Enter contact number to edit: ";
    std::cin >> index;
    std::cin.ignore();

    if (index < 1 || index > (int)contacts.size()) {
        std::cout << "Invalid index!\n";
        return;
    }

    std::string name, phone, address;
    std::cout << "Enter new name: ";
    std::getline(std::cin, name);
    std::cout << "Enter new phone: ";
    std::getline(std::cin, phone);
    std::cout << "Enter new address: ";
    std::getline(std::cin, address);

    contacts[index - 1] = Person(name, phone, address);
    std::cout << "Contact updated successfully!\n";
}

void PhonebookManager::deleteContact() {
    viewContacts();
    if (contacts.empty()) return;

    int index;
    std::cout << "Enter contact number to delete: ";
    std::cin >> index;

    if (index < 1 || index > (int)contacts.size()) {
        std::cout << "Invalid index!\n";
        return;
    }

    contacts.erase(contacts.begin() + (index - 1));
    std::cout << "Contact deleted successfully!\n";
}

void PhonebookManager::searchContact() {
    std::cin.ignore();
    std::string keyword;
    std::cout << "Enter name to search: ";
    std::getline(std::cin, keyword);

    bool found = false;
    for (const auto &c : contacts) {
        if (c.getName().find(keyword) != std::string::npos) {
            c.print();
            std::cout << "-----------------\n";
            found = true;
        }
    }
    if (!found) std::cout << "No contact found with that name.\n";
}

void PhonebookManager::loadFromFile(const std::string &filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cout << "File not found.\n";
        return;
    }

    contacts.clear();
    std::string name, phone, address;
    while (std::getline(inFile, name) && std::getline(inFile, phone) && std::getline(inFile, address)) {
        contacts.push_back(Person(name, phone, address));
    }
    inFile.close();
    std::cout << "Contacts loaded from file.\n";
}

void PhonebookManager::saveToFile(const std::string &filename) {
    std::ofstream outFile(filename);
    for (const auto &c : contacts) {
        outFile << c.getName() << "\n" << c.getPhone() << "\n" << c.getAddress() << "\n";
    }
    outFile.close();
    std::cout << "Contacts saved to file.\n";
}