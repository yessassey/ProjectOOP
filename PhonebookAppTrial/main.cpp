#include <iostream>
#include "PhonebookManager.h"
using namespace std;

int main()
{
    PhonebookManager manager;
    int choice;

    do
    {
        cout << "\n===== PHONEBOOK MENU =====\n";
        cout << "1. Add Contact\n";
        cout << "2. Edit Contact\n";
        cout << "3. Delete Contact\n";
        cout << "4. View All Contacts\n";
        cout << "5. Search Contact\n";
        cout << "6. Load from File\n";
        cout << "7. Save to File\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            manager.addContact();
            break;
        case 2:
            manager.editContact();
            break;
        case 3:
            manager.deleteContact();
            break;
        case 4:
            manager.viewContacts();
            break;
        case 5:
            manager.searchContact();
            break;
        case 6:
            manager.loadFromFile("input.txt");
            break;
        case 7:
            manager.saveToFile("output.txt");
            break;
        case 0:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}