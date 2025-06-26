# Efficient Implementation of Graph Homomorphism Counting Algorithm

## Description

This C++ library computes the number of graph homomorphisms between two graphs H and G using Diaz, Serna and Thilikos's dynamic programming algorithm on a nice tree decomposition. Greedy heuristics are used to find a tree decomposition. 
<br><br>This library also supports the Graphon version in which we represent G as a weighted graph.
<br><br>The complexity of this algorithm is polynomial to the treewdith of the NTD - O(poly(|V(H)|)\*|V(G)|^{tw(H)+1}). If H is a tree, the complexity becomes O(|V(H)|\*|E(G)|).
<br><br>Pybind11 is used to run this library in a Python environment.

## Usage

Define Graph by the number of vertices and add edges using addEdge:
````
from homlib import Graph, countHom

H = Graph(3)
H.addEdge(0, 1)
H.addEdge(1, 2)

G = Graph(3)
G.addEdge(0, 1)
G.addEdge(1, 2)
G.addEdge(2, 0)

print(countHom(H, G))
````

````
12
````
<br>Define Graph by the adjacency matrix:
````
from homlib import Graph, countHom

H = Graph([
    [0, 0, 0, 0, 0, 0, 0, 1, 1, 1],
    [0, 0, 0, 0, 0, 1, 0, 0, 1, 1],
    [0, 0, 0, 0, 0, 1, 1, 0, 0, 1],
    [0, 0, 0, 0, 0, 1, 1, 1, 0, 0],
    [0, 0, 0, 0, 0, 0, 1, 1, 1, 0],
    [0, 1, 1, 1, 0, 0, 0, 0, 0, 0],
    [0, 0, 1, 1, 1, 0, 0, 0, 0, 0],
    [1, 0, 0, 1, 1, 0, 0, 0, 0, 0],
    [1, 1, 0, 0, 1, 0, 0, 0, 0, 0],
    [1, 1, 1, 0, 0, 0, 0, 0, 0, 0]
])

G = Graph([
    [0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0],
    [1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1],
    [1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1],
    [0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0],
    [1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1],
    [0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0],
    [0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0],
    [0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1],
    [1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0],
    [1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1],
    [1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0],
    [0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0]
])

print(countHom(H, G))
````

````
5654308
````

## Installation

````
git clone https://github.com/kevinwangwkw/CountHomLib
pip3 install ./CountHom
````

<br>Note: if there is a ````fatal error: 'omp.h' file not found```` error, try ````brew install llvm```` then copy and paste the following entire block of code into the terminal:
````
LDFLAGS="-L$(brew --prefix llvm)/lib" \
CPPFLAGS="-I$(brew --prefix llvm)/include" \
CC="$(brew --prefix llvm)/bin/clang" \
CXX="$(brew --prefix llvm)/bin/clang++" \
pip3 install ./CountHomLib
````
