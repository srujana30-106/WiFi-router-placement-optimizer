#include "../include/graph_loader.h"
#include "../include/optimizer.h"
#include <iostream>
#include <vector>
#include <fstream> 

using namespace std;

int main() {
    int n, routerRange;
    vector<int> area;
    vector<vector<int>> graph;

    loadGraphFromFile("data/input.txt", n, routerRange, area, graph);
    vector<int> routerPlacedAt = placeRoutersUsingSetCover(n, routerRange, area, graph);

    // Output result
    cout << "Optimal Routers placed at rooms: ";
    for (int room : routerPlacedAt) {
        cout << room << " ";
    }
    cout << endl;

    // Write to routers.txt
    ofstream fout("data/routers.txt");
    for (int room : routerPlacedAt) {
        fout << room << "\n";
    }

    return 0;
}
