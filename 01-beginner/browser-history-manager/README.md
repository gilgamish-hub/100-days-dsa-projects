# Browser History Manager (Doubly Linked List)

## 🚀 Problem
Design a browser history system supporting:
- Visit new pages
- Back & Forward navigation

## 🧠 Approach
Used Doubly Linked List:
- `prev` → back navigation
- `next` → forward navigation
- `current` pointer tracks active page

## ✨ Features
- Timestamp tracking
- LRU-based history limit (50 pages)
- File persistence (save/load)
- Search functionality
- Clear history
- Interactive CLI

## ⚡ Complexity
- Visit: O(1)
- Back/Forward: O(1)
- Search: O(n)

## 🛠 Tech
- C++
- Doubly Linked List
- File Handling

## 📌 Learnings
- Real-world use of linked lists
- Memory management (deletion)
- Designing user-driven systems
