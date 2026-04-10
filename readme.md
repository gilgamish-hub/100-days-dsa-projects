# 🚀 Student Record System (C++ | DSA Project)

## 📌 Overview

A **menu-driven Student Record Management System** built using **C++** and core **Data Structures & Algorithms concepts**.
This project demonstrates how basic DSA (arrays, searching, sorting) can be applied to solve real-world problems.

---

## 🎯 Features

* ➕ Add Student (with duplicate ID prevention)
* 📋 Display all Students (formatted output)
* 🔍 Search Student by ID (Linear Search)
* ✏️ Update Student details
* ❌ Delete Student (with shifting logic)
* 📊 Sort Students by Marks (Descending)

---

## 🧠 DSA Concepts Used

* **Arrays** → storing student records
* **Linear Search** → searching by ID
* **Bubble Sort** → sorting by marks
* **Shifting Technique** → deletion in arrays

---

## ⚙️ Time Complexity

| Operation      | Complexity |
| -------------- | ---------- |
| Add Student    | O(1)       |
| Search Student | O(n)       |
| Update Student | O(n)       |
| Delete Student | O(n)       |
| Sort Students  | O(n²)      |

---

## ❓ Why Linear Search Instead of Binary Search?

Binary Search requires **sorted data**, but in this system:

* Data is **dynamic** (insert, delete, update)
* Records are **not always sorted**

👉 Therefore, **Linear Search ensures correctness**

> Future upgrade: Maintain sorted order to enable Binary Search (O(log n))

---

## 🖥️ Sample Output

```
===== Student Record System =====
1. Add Student
2. Display Students
3. Search Student
4. Update Student
5. Delete Student
6. Sort by Marks
7. Exit
```

---

## ▶️ How to Run

```bash
g++ main.cpp
./a.out
```

---

## 📂 Project Structure

```
student-record-system/
│
├── main.cpp
└── README.md
```

---

## 🚀 Learning Outcomes

* Understood real-world usage of arrays
* Implemented CRUD operations using DSA
* Learned trade-offs between different searching techniques
* Improved modular programming in C++

---

## 🔥 Future Improvements

* 💾 File handling (persistent storage)
* 🔎 Binary Search implementation (with sorted data)
* 📈 Student analytics (average, topper)
* 🌐 Web-based version (React + Backend)

---

## 📅 Progress

✅ Day 1/100 – Completed

---

## ⭐ Author

**Jatin Pal**
B.Tech CSE | DSA & AI/ML Enthusiast
