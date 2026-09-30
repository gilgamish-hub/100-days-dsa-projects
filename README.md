# Data structures in C++: small practical projects

[![build](https://github.com/gilgamish-hub/100-days-dsa-projects/actions/workflows/build.yml/badge.svg)](https://github.com/gilgamish-hub/100-days-dsa-projects/actions/workflows/build.yml)

Each project takes one data structure and uses it for something recognisable, so the choice of structure has a reason.

| Project | Data structure | What it shows |
|---|---|---|
| [Browser History Manager](01-beginner/browser-history-manager) | Doubly linked list | Back and forward navigation in O(1), with history saved to a file |
| [Undo-Redo Text Editor](01-beginner/undo-redo-text-editor) | Two stacks | Undo and redo swap text snapshots between the stacks; a new edit clears redo |
| [Music Playlist](01-beginner/music-playlist) | Doubly circular linked list | Next and previous wrap around the playlist; includes a small web version (HTML/CSS/JS) |
| [Smart Contact Book](01-beginner/smart-contact-book) | Hash map (`unordered_map`) | O(1) lookup by name, with contacts saved to a file |
| [Student Record System](01-beginner/student-record-system) | Array of structs | Add, search, update, delete, and sort by marks |

## Build and run

Every project is a single C++17 file:

```bash
cd 01-beginner/undo-redo-text-editor
g++ -std=c++17 main.cpp -o editor
./editor
```

More of my work: **[gilgamish-hub.github.io](https://gilgamish-hub.github.io)**
