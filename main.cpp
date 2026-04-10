#include <iostream>
#include <iomanip>
using namespace std;

struct Student {
    int id;
    string name;
    float marks;
};

Student s[100];
int count = 0;

// 🔍 Check duplicate ID
bool isDuplicate(int id) {
    for (int i = 0; i < count; i++) {
        if (s[i].id == id)
            return true;
    }
    return false;
}

// ➕ Add Student
void addStudent() {
    if (count >= 100) {
        cout << "❌ Database Full!\n";
        return;
    }

    int id;
    cout << "Enter ID: ";
    cin >> id;

    if (isDuplicate(id)) {
        cout << "❌ ID already exists!\n";
        return;
    }

    cin.ignore(); // clear buffer

    cout << "Enter Full Name: ";
    getline(cin, s[count].name);

    cout << "Enter Marks: ";
    cin >> s[count].marks;

    s[count].id = id;
    count++;

    cout << "✅ Student added successfully!\n";
}

// 📋 Display Students
void displayStudents() {
    if (count == 0) {
        cout << "❌ No records found!\n";
        return;
    }

    cout << "\n--------------------------------------------------\n";
    cout << left << setw(10) << "ID"
         << setw(25) << "Name"
         << setw(10) << "Marks" << endl;
    cout << "--------------------------------------------------\n";

    for (int i = 0; i < count; i++) {
        cout << left << setw(10) << s[i].id
             << setw(25) << s[i].name
             << setw(10) << s[i].marks << endl;
    }
}

// 🔎 Search Student
void searchStudent() {
    int id;
    cout << "Enter ID to search: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (s[i].id == id) {
            cout << "✅ Found: "
                 << s[i].name << " ("
                 << s[i].marks << ")\n";
            return;
        }
    }

    cout << "❌ Student not found!\n";
}

// ✏️ Update Student
void updateStudent() {
    int id;
    cout << "Enter ID to update: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (s[i].id == id) {
            cin.ignore();
            cout << "Enter new name: ";
            getline(cin, s[i].name);

            cout << "Enter new marks: ";
            cin >> s[i].marks;

            cout << "✅ Updated successfully!\n";
            return;
        }
    }

    cout << "❌ Student not found!\n";
}

// ❌ Delete Student
void deleteStudent() {
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (s[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                s[j] = s[j + 1];
            }
            count--;
            cout << "✅ Deleted successfully!\n";
            return;
        }
    }

    cout << "❌ Student not found!\n";
}

// 📊 Sort by Marks (Descending)
void sortStudents() {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (s[j].marks < s[j + 1].marks) {
                swap(s[j], s[j + 1]);
            }
        }
    }

    cout << "✅ Sorted by marks (highest first)\n";
}

// 🏠 Main Menu
int main() {
    int choice;

    while (true) {
        cout << "\n===== Student Record System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Sort by Marks\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: sortStudents(); break;
            case 7: cout << "Exiting...\n"; return 0;
            default: cout << "❌ Invalid choice!\n";
        }
    }
}