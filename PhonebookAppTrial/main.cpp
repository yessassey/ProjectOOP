#include <iostream>
#include "PhonebookManager.h"

int main() {
    PhonebookManager manager;
    int choice;

    do {
        std::cout << "\n===== PHONEBOOK MENU =====\n";
        std::cout << "1. Add Contact\n";
        std::cout << "2. Edit Contact\n";
        std::cout << "3. Delete Contact\n";
        std::cout << "4. View All Contacts\n";
        std::cout << "5. Search Contact\n";
        std::cout << "6. Load from File\n";
        std::cout << "7. Save to File\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose: ";
        std::cin >> choice;

        switch (choice) {
            case 1: manager.addContact(); break;
            case 2: manager.editContact(); break;
            case 3: manager.deleteContact(); break;
            case 4: manager.viewContacts(); break;
            case 5: manager.searchContact(); break;
            case 6: manager.loadFromFile("input.txt"); break;
            case 7: manager.saveToFile("output.txt"); break;
            case 0: std::cout << "Exiting...\n"; break;
            default: std::cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}