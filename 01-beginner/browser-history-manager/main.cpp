#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

const int MAX_SIZE = 50;

struct Node {
    string url;
    string timestamp;
    Node* prev;
    Node* next;

    Node(string u, string t) {
        url = u;
        timestamp = t;
        prev = next = NULL;
    }
};

// Get current time
string getTime() {
    time_t now = time(0);
    string dt = ctime(&now);
    dt.pop_back();
    return dt;
}

class BrowserHistory {
private:
    Node* current;
    Node* head;
    int size;

public:
    BrowserHistory(string homepage) {
        Node* node = new Node(homepage, getTime());
        head = current = node;
        size = 1;
    }

    // 🔹 Visit new page
    void visit(string url) {
        Node* newNode = new Node(url, getTime());

        // delete forward history
        Node* temp = current->next;
        while (temp != NULL) {
            Node* del = temp;
            temp = temp->next;
            delete del;
            size--;
        }

        current->next = newNode;
        newNode->prev = current;
        current = newNode;
        size++;

        // LRU delete oldest if size exceeds
        if (size > MAX_SIZE) {
            Node* del = head;
            head = head->next;
            head->prev = NULL;
            delete del;
            size--;
        }
    }

    void back() {
        if (current->prev != NULL)
            current = current->prev;
        else
            cout << "No back history\n";
    }

    void forward() {
        if (current->next != NULL)
            current = current->next;
        else
            cout << "No forward history\n";
    }

    void showCurrent() {
        cout << "Current: " << current->url
             << " | " << current->timestamp << endl;
    }

    void showHistory() {
        Node* temp = head;
        cout << "\nHistory:\n";
        while (temp != NULL) {
            cout << temp->url << " (" << temp->timestamp << ")";
            if (temp == current) cout << " <-- current";
            cout << endl;
            temp = temp->next;
        }
    }

    // 🔍 Search
    void search(string keyword) {
        Node* temp = head;
        bool found = false;

        cout << "\nSearch Results:\n";
        while (temp != NULL) {
            if (temp->url.find(keyword) != string::npos) {
                cout << temp->url << " (" << temp->timestamp << ")\n";
                found = true;
            }
            temp = temp->next;
        }

        if (!found) cout << "No match found\n";
    }

    // 🧹 Clear History
    void clearHistory() {
        Node* temp = head;
        while (temp != NULL) {
            Node* del = temp;
            temp = temp->next;
            delete del;
        }
        head = current = NULL;
        size = 0;
        cout << "History Cleared\n";
    }

    // 💾 Save to file
    void saveToFile() {
        ofstream file("history.txt");
        Node* temp = head;

        while (temp != NULL) {
            file << temp->url << "|" << temp->timestamp << endl;
            temp = temp->next;
        }

        file.close();
    }

    // 📂 Load from file
    void loadFromFile() {
        ifstream file("history.txt");
        if (!file) return;

        clearHistory();

        string line;
        while (getline(file, line)) {
            int pos = line.find("|");
            string url = line.substr(0, pos);
            string time = line.substr(pos + 1);

            Node* newNode = new Node(url, time);

            if (head == NULL) {
                head = current = newNode;
                size = 1;
            } else {
                current->next = newNode;
                newNode->prev = current;
                current = newNode;
                size++;
            }
        }

        file.close();
    }
};
int main() {
    BrowserHistory bh("homepage.com");

    bh.loadFromFile();

    int choice;
    string url;

    while (true) {
        cout << "\n===== Browser History Menu =====\n";
        cout << "1. Visit Page\n";
        cout << "2. Back\n";
        cout << "3. Forward\n";
        cout << "4. Show Current Page\n";
        cout << "5. Show Full History\n";
        cout << "6. Search\n";
        cout << "7. Clear History\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter URL: ";
                cin >> url;
                bh.visit(url);
                break;

            case 2:
                bh.back();
                break;

            case 3:
                bh.forward();
                break;

            case 4:
                bh.showCurrent();
                break;

            case 5:
                bh.showHistory();
                break;

            case 6:
                cout << "Enter keyword: ";
                cin >> url;
                bh.search(url);
                break;

            case 7:
                bh.clearHistory();
                break;

            case 8:
                bh.saveToFile();
                cout << "Exiting... History saved.\n";
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }
}