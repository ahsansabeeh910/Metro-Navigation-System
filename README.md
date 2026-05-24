<div align="center">

# 🚇 Metro Navigation System

### Graph Theory Based Metro Route & Pathfinding Simulator

![C++](https://img.shields.io/badge/C++-Programming-blue?style=for-the-badge&logo=cplusplus)
![Graph Theory](https://img.shields.io/badge/Graph-Theory-green?style=for-the-badge)
![Dijkstra](https://img.shields.io/badge/Dijkstra-Algorithm-orange?style=for-the-badge)
![Data Structures](https://img.shields.io/badge/Data-Structures-red?style=for-the-badge)

</div>

---

# 📌 Overview

The **Metro Navigation System** is a graph-based pathfinding application developed in C++ that simulates a metro rail network.

The system models:

- Metro stations as vertices
- Routes as weighted edges
- Distances as edge weights

Using **Graph Theory** and **Dijkstra’s Algorithm**, the project efficiently computes:

✅ Shortest Distance  
✅ Minimum Travel Time  
✅ Route Connectivity  
✅ Station Navigation  

This project demonstrates practical applications of:

- Graph Data Structures
- Priority Queues
- Heaps
- Shortest Path Algorithms

in real-world transportation systems.

---

# 🚀 Features

✅ Interactive Metro Map  
✅ Shortest Path Calculation  
✅ Minimum Travel Time Finder  
✅ Route Connectivity Check  
✅ Graph-based Station Modeling  
✅ Dijkstra’s Algorithm Implementation  
✅ Heap & Priority Queue Usage  
✅ Console-based Navigation System  

---

# 🛠️ Tech Stack

| Technology | Purpose |
|------------|----------|
| C++ | Core programming language |
| Graph Theory | Metro network modeling |
| Dijkstra Algorithm | Shortest path calculation |
| STL Priority Queue | Efficient route computation |
| Heap Data Structure | Optimized path processing |

---

# 🧠 Core Concepts Implemented

| Concept | Application |
|---------|-------------|
| Graphs | Metro network representation |
| Weighted Edges | Distance between stations |
| Dijkstra’s Algorithm | Shortest path computation |
| Heaps | Priority-based processing |
| Hash Maps | Fast station lookup |

---

# 🚉 Metro Network Representation

Each station is represented as a node in a graph:

```text id="jmk6n5"
Station → Vertex
Route → Edge
Distance → Edge Weight
```

The metro map is implemented using adjacency lists for efficient graph traversal.

---

# ⚙️ Functionalities

## 1️⃣ Display Metro Map

Displays all stations and their connected neighboring stations.

---

## 2️⃣ Display Station List

Shows all available metro stations in the network.

---

## 3️⃣ Path Existence Check

Determines whether a route exists between two stations using graph traversal.

---

## 4️⃣ Shortest Path Finder

Uses Dijkstra’s Algorithm to calculate minimum distance between stations.

---

## 5️⃣ Minimum Time Calculation

Computes estimated travel time between stations considering edge weights.

---

# 📂 Project Structure

```bash id="trjvhu"
Metro-Navigation-System/
│
├── main.cpp
├── MetroMap.cpp
├── Heap.cpp
├── stations/
└── README.md
```

---

# 📥 Installation

## Clone Repository

```bash id="8a2o8k"
git clone https://github.com/your-username/Metro-Navigation-System.git
```

## Navigate to Project

```bash id="p2jx5d"
cd Metro-Navigation-System
```

## Compile Program

```bash id="2xqz0o"
g++ main.cpp -o metro
```

---

# ▶️ Run Project

```bash id="n50d6n"
./metro
```

For Windows:

```bash id="h9odmo"
metro.exe
```

---

# 📊 Algorithms Used

## 🔹 Dijkstra’s Algorithm

Used to compute:

- Shortest route
- Minimum distance
- Minimum travel time

### Time Complexity

```text id="0y4yaf"
O((V + E) log V)
```

where:
- V = Number of Stations
- E = Number of Routes

---

# 🖥️ Sample Features

- Noida Sector 62 → Botanical Garden
- Rajiv Chowk → Vaishali
- AIIMS → IGI Airport
- Dwarka Sector 21 connectivity

The system supports multiple metro route calculations dynamically.

---

# 📈 Learning Outcomes

- Understanding graph-based transportation systems
- Implementing shortest path algorithms
- Working with heaps and priority queues
- Efficient route optimization techniques
- Practical application of Dijkstra Algorithm

---

# 🔮 Future Improvements

- GUI-based Metro Visualization
- Real-time Route Updates
- Fare Calculation System
- Multi-line Metro Integration
- Interactive Map Interface
- GPS & Live Tracking Integration

---

# 📚 References

1. Graph Theory Algorithms
2. Dijkstra’s Shortest Path Algorithm
3. C++ STL Documentation
4. Transportation Network Optimization Concepts

---

# 👨‍💻 Author

### Sabeeh Ahsan

**Jaypee Institute of Information Technology**

---
