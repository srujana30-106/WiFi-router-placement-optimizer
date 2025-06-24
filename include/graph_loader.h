#pragma once
#include <vector>
#include <string>

void loadGraphFromFile(const std::string& filename, int& n, int& routerRange,
                       std::vector<int>& area,
                       std::vector<std::vector<int>>& graph);
