# WiFi Router Placement Optimizer

An algorithmic solution to minimize the number of WiFi routers required to ensure complete coverage of connected rooms using graph theory and greedy Set Cover Approximation.

## Problem Statement

You are given:
- A list of rooms with their area sizes
- A maximum range a WiFi router can cover based on total area

Goal: Place the minimum number of routers such that all rooms are covered. A router placed in a room can cover it and adjacent rooms as long as the total area covered does not exceed the router's range.

## Approach & Algorithms Used

The problem is modeled as a graph coverage optimization problem and solved using:
- Graph Representation (Adjacency List)
- Breadth-First Search (BFS) for reachable room detection under area constraints
- Greedy Set Cover Approximation to iteratively choose the best placement

## Data Structures & Algorithms (DSA) Used

- Graph Traversal: BFS
- Greedy Algorithm: Set Cover Approximation
- Data Structures:
  - std::vector for graph and area storage
  - std::queue for BFS traversal
  - std::set to track reachable and covered rooms
  - std::ifstream / ofstream for file I/O

## Tools & Technologies

- C++ – Core implementation and algorithm logic
- MSYS2 – Build and execution environment (on Windows)
- OpenGL + GLUT – Visualization of router placement
- Makefile – For compiling project components

## Project Structure

wifi-router-optimizer/
├── data/
│   ├── input.txt         # Room/graph input
│   └── routers.txt       # Output: router placements
├── include/
│   ├── graph_loader.h
│   └── optimizer.h
├── src/
│   ├── graph_loader.cpp  # File input loader
│   ├── optimizer.cpp     # BFS + greedy algorithm
│   ├── main.cpp          # Main runner
│   └── visualizer.cpp    # OpenGL visualizer
├── bin/                  # Compiled binaries
├── Makefile              # Build automation
└── README.md             # Project documentation

## How to Run

### Prerequisites
- C++ compiler (g++)
- MSYS2 (on Windows)
- OpenGL and GLUT libraries

### Build the Project
Run the following from the project root:

make

This creates two binaries:
- bin/main – runs the router placement algorithm
- bin/vis – launches the visualizer

### Execute

1. Prepare your data/input.txt with room and edge data  
2. Run optimization:

./bin/main

3. Run visualization:

./bin/vis

## Input File Format (data/input.txt)

<Number of Rooms> <Router Range>  
<Area_1> <Area_2> ... <Area_n>  
<Number of Edges>  
<Room_u1> <Room_v1>  
<Room_u2> <Room_v2>  
...

### Example

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

## Visualization

The OpenGL visualizer (vis) displays rooms as rectangles.
- Green rooms indicate router placements
- Light blue rooms indicate covered areas
Each room is labeled with its ID for clarity.

## Project Highlights

- Solved a real-world optimization problem using fundamental DSA
- Showcases strong knowledge of graphs, BFS, and greedy strategies
- Cleanly separates logic (algorithm) and GUI (OpenGL) for maintainability

## License

This project is for academic and personal use only.

## Contributing

Feel free to fork the repo, suggest improvements, or open issues.

## Acknowledgments

Developed using MSYS, OpenGL, and classic algorithmic techniques.
