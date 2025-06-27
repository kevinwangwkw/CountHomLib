# Efficient Implementation of Graph Homomorphism Counting Algorithm

## Description

This C++ library computes the number of graph homomorphisms between two graphs H and G using Diaz, Serna and Thilikos's dynamic programming algorithm on a nice tree decomposition. Greedy heuristics - specifically minimum degree - are used to find a tree decomposition. 
<br><br>This library also supports the graphon version in which G is represented as a weighted graph.
<br><br>The complexity of this algorithm is polynomial to the treewdith of the NTD - O(poly(|V(H)|)\*|V(G)|^{tw(H)+1}). If H is a tree, the complexity becomes O(|V(H)|\*|E(G)|).
<br><br>Pybind11 is used to run this library in a Python environment.

## Usage (Standard Graphs)

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

## Usage (Graphons)

Define Graphon by a weighted adjacency matrix:
````
from homlib import Graph, Graphon, countHomGraphon

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

G = Graphon([
 [0.5, 0.88, 0.6, 0.99],
 [0.88, 0.3, 0.21, 0.34],
 [0.6, 0.21, 0.2, 0.78],
 [0.99, 0.34, 0.78, 0.14]
])

print(countHomGraphon(H, G))
````

````
0.00036733029704778646
````

Normalisation could also be turned off for certain applications:
````
print(countHomGraphon(H, G, normalise = False))
````

````
385.17373355717973
````

## Helper Functions
Get greedy treewidth of a graph from its adjacency matrix:
````
from homlib import treewidth

tw = treewidth([
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

print(tw)
````

````
4
````

## Installation

````
git clone https://github.com/kevinwangwkw/CountHomLib
pip3 install ./CountHomLib
````

<br>Note: if there is a ````fatal error: 'omp.h' file not found```` error, try ````brew install llvm```` then copy and paste the following entire block of code into the terminal:
````
LDFLAGS="-L$(brew --prefix llvm)/lib" \
CPPFLAGS="-I$(brew --prefix llvm)/include" \
CC="$(brew --prefix llvm)/bin/clang" \
CXX="$(brew --prefix llvm)/bin/clang++" \
pip3 install ./CountHomLib
````
