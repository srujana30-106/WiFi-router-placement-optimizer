# WiFi Router Placement Optimizer

An algorithmic solution to minimize the number of WiFi routers required to ensure complete coverage of connected rooms, using **graph theory** and a **greedy Set Cover Approximation**.

---

## Problem Statement

You are given:
- A list of rooms with their area sizes.
- A maximum range a WiFi router can cover based on total area.

**Goal:**  
Place the **minimum number of routers** such that all rooms are covered.  
A router placed in a room can cover it and its adjacent rooms, as long as the total area does not exceed the router's range.

---

## Approach & Algorithms Used

This problem is modeled as a **graph coverage optimization problem** and solved using:
- **Graph Representation** via Adjacency List
- **Breadth-First Search (BFS)** to detect reachable rooms under area constraints
- **Greedy Set Cover Approximation** to iteratively pick the best placement

---

## Data Structures & Algorithms (DSA) Used

- Graph traversal: **BFS**
- Greedy Algorithm: **Set Cover Approximation**
- STL containers:
  - `std::vector` — graph and area storage
  - `std::queue` — BFS traversal
  - `std::set` — track reachable & covered rooms
- File I/O with `std::ifstream` / `ofstream`

---

## 🛠 Tech Stack & Tools

- **Language:** C++ (core logic & algorithms)
- **Build Environment:** MSYS2 on Windows
- **Visualization:** OpenGL + GLUT
- **Build Automation:** Makefile

---

## Project Structure

```
wifi-router-optimizer/
├── data/
│   ├── input.txt         # Input graph & areas
│   └── routers.txt       # Output router placements
├── include/
│   ├── graph_loader.h
│   └── optimizer.h
├── src/
│   ├── graph_loader.cpp
│   ├── optimizer.cpp
│   ├── main.cpp
│   └── visualizer.cpp
├── bin/                  # Compiled binaries
├── Makefile
└── README.md
```

---

##  How to Build & Run

### Prerequisites
- C++ compiler (g++)
- MSYS2 (on Windows)
- OpenGL + GLUT installed

### Build
Run from the project root:

```bash
make
```

This will create:
- `bin/main` — runs the optimization algorithm
- `bin/vis` — launches the OpenGL visualizer

---

###  Run

Prepare your input data in `data/input.txt`.  
Run the optimizer:

```
./bin/main
```

View the results in the visualizer:

```
./bin/vis
```

---

## Input File Format (`data/input.txt`)

```
<Number of Rooms> <Router Range>
<Area_1> <Area_2> ... <Area_n>
<Number of Edges>
<Room_u1> <Room_v1>
<Room_u2> <Room_v2>
...
```

#### Example
```
10 130
60 42 45 57 45 45 45 46 64 50
12
1 2
2 3
3 4
4 5
5 7
7 6
6 3
5 8
8 9
9 10
10 1
10 2
```

---

##  Visualization

- Rooms are displayed as rectangles using OpenGL.
- **Green:** rooms where routers are placed.
- **Light blue:** rooms covered by those routers.
- Each room is labeled with its ID for clarity.

---

## Project Highlights

 Solves a **real-world optimization problem** using fundamental DSA.  
 Demonstrates strong understanding of **graphs, BFS, greedy heuristics**.  
 Clean separation between **algorithm logic** and **GUI visualization** for maintainability.

---

##  License

This project is for **academic & personal use only**.

---

##  Contributing

Feel free to **fork**, open issues, or suggest improvements!

---

##  Acknowledgments

Built using:
- **MSYS2** for C++ build environment on Windows
- **OpenGL + GLUT** for visualization
- Classic graph & algorithm techniques from fundamental DSA
