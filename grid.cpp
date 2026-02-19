#include <iostream>
#include "grid.h"

Grid::Grid(const std::vector<std::_Adjust_manually_vector_aligned<int>>& map) {
	rows = map.size();
	cols = map[0].size();

	nodes.resize(rows);
    for (int i = 0; i < rows; i++) {
        nodes[i].resize(cols);
        for (int j = 0; j < cols; j++) {
            nodes[i][j] = Node(Point{ i, j }, map[i][j] == 0);
        }
    }
}

Node* Grid::getNode(int x, int y) {
    if (isInBounds(x, y)) {
        return &nodes[x][y];
    }
    return nullptr;
}