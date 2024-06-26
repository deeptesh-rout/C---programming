#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Contact {
public:
    string name;
    string phoneNumber;
    string email;

    Contact(string n, string p, string e) : name(n), phoneNumber(p), email(e) {}

    void display() const {
        cout << "Name: " << name << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Email: " << email << endl;
        cout << "--------------------" << endl;
    }
};

class AddressBook {
private:
    vector<Contact> contacts;
    int capacity;

public:
    AddressBook(int cap) : capacity(cap) {}

    void addContact(string name, string phoneNumber, string email) {
        if (contacts.size() < capacity) {
            contacts.emplace_back(name, phoneNumber, email);
            cout << "Contact added successfully!" << endl;
        } else {
            cout << "Address book is full. Cannot add more contacts." << endl;
        }
    }

    void displayContacts() const {
        if (contacts.empty()) {
            cout << "Address book is empty." << endl;
        } else {
            cout << "Listing all contacts:" << endl;
            for (const auto& contact : contacts) {
                contact.display();
            }
        }
    }

    void search(const string& keyword) const {
        bool found = false;
        for (const auto& contact : contacts) {
            if (contact.name == keyword || contact.phoneNumber == keyword) {
                cout << "Contact found:" << endl;
                contact.display();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Contact not found." << endl;
        }
    }

    void addAll(const vector<Contact>& newContacts) {
        if (contacts.size() + newContacts.size() > capacity) {
            cout << "Not enough space to add all contacts." << endl;
        } else {
            contacts.insert(contacts.end(), newContacts.begin(), newContacts.end());
            cout << "Contacts added successfully!" << endl;
        }
    }

    int getSize() const {
        return contacts.size();
    }

    void clear() {
        contacts.clear();
        cout << "Address book cleared." << endl;
    }

    void remove(const string& name) {
        auto it = remove_if(contacts.begin(), contacts.end(),
                            [&](const Contact& contact) { return contact.name == name; });
        if (it != contacts.end()) {
            contacts.erase(it, contacts.end());
            cout << "Contact removed successfully." << endl;
        } else {
            cout << "Contact not found." << endl;
        }
    }

    void sortByNumber() {
        sort(contacts.begin(), contacts.end(),
             [](const Contact& a, const Contact& b) { return a.phoneNumber < b.phoneNumber; });
        cout << "Contacts sorted by phone number." << endl;
    }

    void sortByName() {
        sort(contacts.begin(), contacts.end(),
             [](const Contact& a, const Contact& b) { return a.name < b.name; });
        cout << "Contacts sorted by name." << endl;
    }
};

int main() {
    AddressBook addressBook(100); // Initialize with capacity for 100 contacts
    int choice;

    while (true) {
        cout << "Address Book Menu:" << endl;
        cout << "1. Add a new contact" << endl;
        cout << "2. Add multiple contacts" << endl;
        cout << "3. Display all contacts" << endl;
        cout << "4. Search for a contact by name or phone number" << endl;
        cout << "5. Remove a contact by name" << endl;
        cout << "6. Sort contacts by name" << endl;
        cout << "7. Sort contacts by phone number" << endl;
        cout << "8. Get size of address book" << endl;
        cout << "9. Clear address book" << endl;
        cout << "10. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore the newline character after the integer input

        switch (choice) {
            case 1: {
                string name, phoneNumber, email;
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter phone number: ";
                getline(cin, phoneNumber);
                cout << "Enter email: ";
                getline(cin, email);
                addressBook.addContact(name, phoneNumber, email);
                break;
            }
            case 2: {
                int numContactsToAdd;
                cout << "Enter number of contacts to add: ";
                cin >> numContactsToAdd;
                cin.ignore();
                vector<Contact> newContacts;
                for (int i = 0; i < numContactsToAdd; ++i) {
                    string name, phoneNumber, email;
                    cout << "Contact " << (i + 1) << ":" << endl;
                    cout << "Enter name: ";
                    getline(cin, name);
                    cout << "Enter phone number: ";
                    getline(cin, phoneNumber);
                    cout << "Enter email: ";
                    getline(cin, email);
                    newContacts.emplace_back(name, phoneNumber, email);
                }
                addressBook.addAll(newContacts);
                break;
            }
            case 3:
                addressBook.displayContacts();
                break;
            case 4: {
                string keyword;
                cout << "Enter name or phone number to search: ";
                getline(cin, keyword);
                addressBook.search(keyword);
                break;
            }
            case 5: {
                string removeName;
                cout << "Enter name to remove: ";
                getline(cin, removeName);
                addressBook.remove(removeName);
                break;
            }
            case 6:
                addressBook.sortByName();
                break;
            case 7:
                addressBook.sortByNumber();
                break;
            case 8:
                cout << "Current size of address book: " << addressBook.getSize() << endl;
                break;
            case 9:
                addressBook.clear();
                break;
            case 10:
                cout << "Exiting address book. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 10." << endl;
        }
        cout << endl; // Add a blank line for readability
    }
}
