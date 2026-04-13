# 📝 Undo-Redo Text Editor (Stack Based)

## 🚀 Project Overview

This project demonstrates the implementation of an **Undo-Redo system** using the **Stack data structure** in C++.

It simulates a basic text editor where users can:

* Type text
* Undo previous actions
* Redo undone actions

---

## 🧠 Concept Used

* Stack (LIFO - Last In First Out)
* Two stacks:

  * `undoStack`
  * `redoStack`

---

## 🔄 Working Mechanism

### ✅ Type Operation

* Save current state in `undoStack`
* Add new text
* Clear `redoStack`

### ✅ Undo Operation

* Move current state to `redoStack`
* Restore last state from `undoStack`

### ✅ Redo Operation

* Move state back from `redoStack` to `undoStack`

---

## ⚙️ Features

* Interactive CLI-based editor
* Supports multiple undo/redo operations
* Handles edge cases (empty stacks)

---

## 🛠️ Tech Stack

* C++
* Standard Template Library (STL)

---

## ▶️ How to Run

```bash
g++ main.cpp -o editor
./editor
```

---

## 📌 Example

```
Type: Hello
Type: World
Undo → Hello
Redo → HelloWorld
```

---

## 📈 Future Improvements

* Store operations instead of full text (optimized version)
* GUI-based editor
* File save/load functionality

---

## 💡 Learning Outcome

* Deep understanding of stack applications
* Real-world use case of DSA
* Foundation for advanced systems like text editors

---

## ⭐ Contribution

Feel free to fork and improve this project!
