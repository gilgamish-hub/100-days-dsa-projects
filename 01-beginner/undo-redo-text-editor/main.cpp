#include <iostream>
#include <stack>
using namespace std;

class TextEditor {
private:
    string text;
    stack<string> undoStack;
    stack<string> redoStack;

public:
    void type(string input) {
        undoStack.push(text);
        text += input;

        // clear redo stack
        while (!redoStack.empty()) redoStack.pop();
    }

    void undo() {
        if (undoStack.empty()) {
            cout << "Nothing to undo\n";
            return;
        }

        redoStack.push(text);
        text = undoStack.top();
        undoStack.pop();
    }

    void redo() {
        if (redoStack.empty()) {
            cout << "Nothing to redo\n";
            return;
        }

        undoStack.push(text);
        text = redoStack.top();
        redoStack.pop();
    }

    void show() {
        cout << "Current Text: " << text << endl;
    }
};

int main() {
    TextEditor editor;
    int choice;
    string input;

    while (true) {
        cout << "\n===== Undo-Redo Text Editor =====\n";
        cout << "1. Type Text\n";
        cout << "2. Undo\n";
        cout << "3. Redo\n";
        cout << "4. Show Text\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter text: ";
                getline(cin, input);
                editor.type(input);
                break;
            case 2:
                editor.undo();
                break;
            case 3:
                editor.redo();
                break;
            case 4:
                editor.show();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
}