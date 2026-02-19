#pragma once
#ifndef GRID_H
#define GRID_H

#include "Node.h"
#include <vector>

class Grid {
public:
    int rows, cols;
    std::vector<std::vector<Node>> nodes;

    Grid(const std::vector<std::vector<int>>& map);

    Node* getNode(int x, int y);
    bool isInBounds(int x, int y) const;
    std::vector<Node*> getNeighbors(Node* node);
    void printGrid() const;
    void printPath(const std::vector<Node*>& path) const;
};

#endif
