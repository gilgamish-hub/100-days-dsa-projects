#include <iostream>
using namespace std;

class Node {
public:
    string song;
    Node* next;
    Node* prev;

    Node(string s) {
        song = s;
        next = prev = NULL;
    }
};

class Playlist {
private:
    Node* head;

public:
    Playlist() {
        head = NULL;
    }

    // Add song
    void addSong(string songName) {
        Node* newNode = new Node(songName);

        if (head == NULL) {
            head = newNode;
            head->next = head;
            head->prev = head;
            return;
        }

        Node* last = head->prev;

        last->next = newNode;
        newNode->prev = last;
        newNode->next = head;
        head->prev = newNode;
    }

    // Display playlist with Now Playing
    void display(Node* current) {
        if (head == NULL) {
            cout << "Playlist is empty\n";
            return;
        }

        Node* temp = head;
        cout << "\nPlaylist:\n";

        do {
            if (temp == current)
                cout << "[Now Playing: " << temp->song << "] <-> ";
            else
                cout << temp->song << " <-> ";

            temp = temp->next;
        } while (temp != head);

        cout << "(circular)\n";
    }

    // Delete song
    void deleteSong(string key, Node*& current) {
        if (head == NULL) {
            cout << "Playlist empty\n";
            return;
        }

        Node* curr = head;

        // Single node
        if (head->song == key && head->next == head) {
            delete head;
            head = NULL;
            current = NULL;
            cout << "Deleted\n";
            return;
        }

        // Delete head
        if (head->song == key) {
            Node* last = head->prev;

            if (current == head)
                current = head->next;

            head = head->next;
            last->next = head;
            head->prev = last;

            delete curr;
            cout << "Deleted\n";
            return;
        }

        // General case
        do {
            if (curr->song == key) {

                if (current == curr)
                    current = curr->next;

                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;

                delete curr;
                cout << "Deleted\n";
                return;
            }
            curr = curr->next;
        } while (curr != head);

        cout << "Song not found\n";
    }

    Node* getHead() {
        return head;
    }
};

// Show current song
void showCurrent(Node* current) {
    if (current != NULL)
        cout << "🎧 Now Playing: " << current->song << endl;
    else
        cout << "Playlist empty\n";
}

int main() {
    Playlist p;
    Node* current = NULL;
    int choice;
    string song;

    do {
        cout << "\n===== MUSIC PLAYLIST MENU =====\n";
        cout << "1. Add Song\n";
        cout << "2. Delete Song\n";
        cout << "3. Display Playlist\n";
        cout << "4. Play Next Song\n";
        cout << "5. Play Previous Song\n";
        cout << "6. Show Now Playing\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter song name: ";
            cin.ignore();
            getline(cin, song);
            p.addSong(song);

            if (current == NULL)
                current = p.getHead();

            break;

        case 2:
            cout << "Enter song to delete: ";
            cin.ignore();
            getline(cin, song);
            p.deleteSong(song, current);
            break;

        case 3:
            p.display(current);
            break;

        case 4:
            if (current != NULL) {
                current = current->next;
                cout << "Now Playing: " << current->song << endl;
            } else {
                cout << "Playlist empty\n";
            }
            break;

        case 5:
            if (current != NULL) {
                current = current->prev;
                cout << "Now Playing: " << current->song << endl;
            } else {
                cout << "Playlist empty\n";
            }
            break;

        case 6:
            showCurrent(current);
            break;

        case 7:
            cout << "Exiting...\n";
            break;


        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 7);

    return 0;
}