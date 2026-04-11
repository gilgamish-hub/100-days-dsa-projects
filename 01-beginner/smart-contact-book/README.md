# 📒 Smart Contact Book (C++)

A feature-rich Contact Management System built using **C++**, implementing core **Data Structures and Algorithms concepts** like **Doubly Linked List**, **Hashing**, and **File Handling**.

---

## 🚀 Features

* ➕ Add new contacts
* 📋 Display all contacts
* 🔍 Search contact (O(1) using Hash Map)
* ❌ Delete contact
* ✏️ Update contact details
* 🔤 Sort contacts (A–Z)
* 💾 Persistent storage using file handling
* 🧠 Efficient data access with hashing

---

## 🧱 Data Structures Used

| Feature     | Data Structure             |
| ----------- | -------------------------- |
| Storage     | Doubly Linked List         |
| Fast Search | Hash Map (`unordered_map`) |
| Persistence | File Handling (`fstream`)  |

---

## ⚙️ How It Works

* Contacts are stored in a **Doubly Linked List**
* Each node contains:

  * Name
  * Phone
  * Email
  * Address
* A **Hash Map** maps names → node pointers for **O(1) search**
* Data is saved in a file (`contacts.txt`) for persistence

---

## 🖥️ Menu Options

```
===== SMART CONTACT BOOK =====
1. Add
2. Display
3. Search
4. Delete
5. Update
6. Sort
7. Exit
```

---

## 🛠️ How to Run

### 🔹 Compile

```bash
g++ contact_book.cpp -o contact
```

### 🔹 Run

```bash
./contact
```

---

## 📁 File Structure

```
📦 Smart-Contact-Book
 ┣ 📜 contact_book.cpp
 ┣ 📄 contacts.txt (auto-generated)
 ┗ 📄 README.md
```

---

## 📌 Key Concepts Implemented

* Doubly Linked List (Insertion, Deletion, Traversal)
* Hashing for efficient lookup
* File I/O operations (Read/Write)
* Object-Oriented Programming (OOP)
* Dynamic Memory Management

---

## ⏱️ Time Complexity

| Operation      | Complexity |
| -------------- | ---------- |
| Add Contact    | O(n)       |
| Search Contact | O(1)       |
| Delete Contact | O(n)       |
| Update Contact | O(1)       |
| Sort Contacts  | O(n²)      |

---

## 💡 Future Enhancements

* 🌐 Convert to Web App (React + Backend)
* 🗄️ Use Database (MongoDB / MySQL)
* 🔐 Add authentication system
* 📱 Build GUI version (Qt / Tkinter)

---

## 👨‍💻 Author

**Jatin Pal**
B.Tech CSE Student

---

## ⭐ Project Highlights

✔ Beginner to Advanced DSA application
✔ Real-world problem solving
✔ Resume-ready project
✔ Strong foundation for backend development

---

## 📬 Feedback

Feel free to contribute or suggest improvements!

---
