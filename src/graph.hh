#pragma once

#include <vector>
#include <algorithm>

struct Graph {
    int n;
    std::vector<std::vector<int>> adj;

    Graph(int n) : n(n), adj(n) { }
    Graph(const std::vector<std::vector<int>>& matrix) {
        n = matrix.size();
        adj.assign(n, {});
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && matrix[i][j]) {
                    adj[i].push_back(j);
                }
            }
            std::sort(adj[i].begin(), adj[i].end());
            adj[i].erase(std::unique(adj[i].begin(), adj[i].end()), adj[i].end());
        }
    }

    void addEdge(int u, int v) {
        if (u == v) return;
        if (!std::binary_search(adj[u].begin(), adj[u].end(), v)) {
            adj[u].insert(std::upper_bound(adj[u].begin(), adj[u].end(), v), v);
            adj[v].insert(std::upper_bound(adj[v].begin(), adj[v].end(), u), u);
        }
    }
};

struct Graphon {
    int n;
    std::vector<std::vector<double>> mat;

    Graphon(const std::vector<std::vector<double>>& matrix) : n(matrix.size()), mat(matrix) { }
};

bool isTree(Graph G) {
    std::vector<int> parent(G.n, -1);
    std::vector<int> stack = {0};

    for (int i = 0; i < stack.size(); ++i) {
        int u = stack[i];
        for (int v: G.adj[u]) {
            if (v == parent[u]) continue;
            if (parent[v] >= 0) return false;
            parent[v] = u;
            stack.push_back(v);
        }
    }
    return stack.size() == G.n;
}

std::vector<Graph> connectedComponents(Graph G) {
    std::vector<int> index(G.n, -1);
    std::vector<Graph> components;

    for (int s = 0; s < G.n; ++s) {
        if (index[s] >= 0) continue;
        index[s] = 0;
        std::vector<int> stack = {s};
        for (int i = 0; i < stack.size(); ++i) {
            int u = stack[i];
            for (int v: G.adj[u]) {
                if (index[v] >= 0) continue;
                index[v] = stack.size();
                stack.emplace_back(v);
            }
        }
        Graph H(stack.size());
        for (int u: stack) {
            for (int v: G.adj[u]) {
                if (u >= v) continue;
                H.addEdge(index[u], index[v]);
            }
        }
        components.emplace_back(H);
    }
    return components;
}
