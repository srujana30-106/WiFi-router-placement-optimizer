#include "../include/graph_loader.h"
#include <fstream>
#include <iostream>

void loadGraphFromFile(const std::string& filename, int& n, int& routerRange,
                       std::vector<int>& area, std::vector<std::vector<int>>& graph) {
    std::ifstream fin(filename);
    if (!fin.is_open()) {
        std::cerr << "Error: Cannot open file " << filename << std::endl;
        exit(1);
    }

    fin >> n >> routerRange;
    area.resize(n + 1);
    graph.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        fin >> area[i];
    }

    int m;
    fin >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        fin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}
