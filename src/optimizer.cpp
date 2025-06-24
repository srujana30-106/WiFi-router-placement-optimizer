#include "../include/optimizer.h"
#include <set>
#include <queue>
#include <algorithm>

std::set<int> bfs_cover(int start, const std::vector<int>& area,
                        const std::vector<std::vector<int>>& graph,
                        const std::vector<bool>& covered, int routerRange) {
    std::queue<std::pair<int, int>> q;
    std::set<int> reachable;
    std::vector<bool> visited(area.size(), false);

    q.push({start, area[start]});
    visited[start] = true;

    if (!covered[start] && area[start] <= routerRange)
        reachable.insert(start);
    else
        return reachable;

    while (!q.empty()) {
        int curr = q.front().first;
        int currArea = q.front().second;
        q.pop();

        for (int neighbor : graph[curr]) {
            if (!visited[neighbor] && !covered[neighbor] && currArea + area[neighbor] <= routerRange) {
                visited[neighbor] = true;
                reachable.insert(neighbor);
                q.push({neighbor, currArea + area[neighbor]});
            }
        }
    }

    return reachable;
}

std::vector<int> placeRoutersUsingSetCover(int n, int routerRange,
                                           std::vector<int>& area,
                                           std::vector<std::vector<int>>& graph) {
    std::vector<bool> covered(n + 1, false);
    std::vector<int> routerPlacedAt;

    while (true) {
        int bestRoom = -1;
        std::set<int> bestCoverage;
        int maxCover = 0;

        for (int i = 1; i <= n; ++i) {
            if (covered[i]) continue;
            std::set<int> reachable = bfs_cover(i, area, graph, covered, routerRange);
            if ((int)reachable.size() > maxCover) {
                maxCover = reachable.size();
                bestCoverage = reachable;
                bestRoom = i;
            }
        }

        if (maxCover == 0) {
            for (int i = 1; i <= n; ++i) {
                if (!covered[i]) {
                    routerPlacedAt.push_back(i);
                    covered[i] = true;
                    break;
                }
            }
        } else {
            routerPlacedAt.push_back(bestRoom);
            for (int room : bestCoverage)
                covered[room] = true;
        }

        if (std::all_of(covered.begin() + 1, covered.end(), [](bool c) { return c; }))
            break;
    }

    return routerPlacedAt;
}
