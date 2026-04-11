#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;

class Contact {
public:
    string name, phone, email, address;
    Contact* next;
    Contact* prev;

    Contact(string n, string p, string e, string a) {
        name = n;
        phone = p;
        email = e;
        address = a;
        next = prev = NULL;
    }
};

class ContactBook {
private:
    Contact* head;
    unordered_map<string, Contact*> contactMap;

public:
    ContactBook() {
        head = NULL;
        loadFromFile();
    }

    // Destructor (memory cleanup)
    ~ContactBook() {
        Contact* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    // ADD CONTACT
    void addContact(string name, string phone, string email, string address) {

        if (contactMap.find(name) != contactMap.end()) {
            cout << "Contact already exists!\n";
            return;
        }

        Contact* newNode = new Contact(name, phone, email, address);

        if (!head) {
            head = newNode;
        } else {
            Contact* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }

        contactMap[name] = newNode;
        cout << "Contact Added!\n";
        saveToFile();
    }

    // DISPLAY
    void displayContacts() {
        if (!head) {
            cout << "No contacts!\n";
            return;
        }

        Contact* temp = head;
        while (temp) {
            cout << "\nName: " << temp->name
                 << "\nPhone: " << temp->phone
                 << "\nEmail: " << temp->email
                 << "\nAddress: " << temp->address << endl;
            temp = temp->next;
        }
    }

    // SEARCH
    void searchContact(string name) {
        if (contactMap.find(name) != contactMap.end()) {
            Contact* c = contactMap[name];
            cout << "\nFound Contact:\n";
            cout << c->name << " | " << c->phone << " | "
                 << c->email << " | " << c->address << endl;
        } else {
            cout << "Contact not found!\n";
        }
    }

    // DELETE
    void deleteContact(string name) {
        if (contactMap.find(name) == contactMap.end()) {
            cout << "Not found!\n";
            return;
        }

        Contact* del = contactMap[name];

        if (del == head) {
            head = head->next;
            if (head) head->prev = NULL;
        } else {
            del->prev->next = del->next;
            if (del->next) del->next->prev = del->prev;
        }

        contactMap.erase(name);
        delete del;

        cout << "Deleted!\n";
        saveToFile();
    }

    // UPDATE
    void updateContact(string name) {
        if (contactMap.find(name) == contactMap.end()) {
            cout << "Not found!\n";
            return;
        }

        Contact* c = contactMap[name];

        cout << "Enter new phone: ";
        cin >> c->phone;

        cin.ignore();
        cout << "Enter new email: ";
        getline(cin, c->email);

        cout << "Enter new address: ";
        getline(cin, c->address);

        cout << "Updated!\n";
        saveToFile();
    }

    // SORT (A-Z)
    void sortContacts() {
        if (!head) return;

        for (Contact* i = head; i != NULL; i = i->next) {
            for (Contact* j = i->next; j != NULL; j = j->next) {
                if (i->name > j->name) {
                    swap(i->name, j->name);
                    swap(i->phone, j->phone);
                    swap(i->email, j->email);
                    swap(i->address, j->address);
                }
            }
        }

        // rebuild hashmap after sorting
        contactMap.clear();
        Contact* temp = head;
        while (temp) {
            contactMap[temp->name] = temp;
            temp = temp->next;
        }

        cout << "Sorted A-Z!\n";
        saveToFile();
    }

    // SAVE TO FILE
    void saveToFile() {
        ofstream file("contacts.txt");

        Contact* temp = head;
        while (temp) {
            file << temp->name << "," << temp->phone << ","
                 << temp->email << "," << temp->address << endl;
            temp = temp->next;
        }

        file.close();
    }

    // LOAD FROM FILE
    void loadFromFile() {
        ifstream file("contacts.txt");
        if (!file) return;

        string name, phone, email, address;

        while (getline(file, name, ',')) {
            getline(file, phone, ',');
            getline(file, email, ',');
            getline(file, address);

            Contact* newNode = new Contact(name, phone, email, address);

            if (!head) {
                head = newNode;
            } else {
                Contact* temp = head;
                while (temp->next) temp = temp->next;
                temp->next = newNode;
                newNode->prev = temp;
            }

            contactMap[name] = newNode;
        }

        file.close();
    }
};

int main() {
    ContactBook cb;
    int choice;
    string name, phone, email, address;

    do {
        cout << "\n===== SMART CONTACT BOOK =====\n";
        cout << "1. Add\n2. Display\n3. Search\n4. Delete\n5. Update\n6. Sort\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cin.ignore();
                cout << "Name: ";
                getline(cin, name);

                cout << "Phone: ";
                cin >> phone;

                cin.ignore();
                cout << "Email: ";
                getline(cin, email);

                cout << "Address: ";
                getline(cin, address);

                cb.addContact(name, phone, email, address);
                break;

            case 2:
                cb.displayContacts();
                break;

            case 3:
                cin.ignore();
                cout << "Enter name: ";
                getline(cin, name);
                cb.searchContact(name);
                break;

            case 4:
                cin.ignore();
                cout << "Enter name: ";
                getline(cin, name);
                cb.deleteContact(name);
                break;

            case 5:
                cin.ignore();
                cout << "Enter name: ";
                getline(cin, name);
                cb.updateContact(name);
                break;

            case 6:
                cb.sortContacts();
                break;

        }

    } while (choice != 7);

    return 0;
}