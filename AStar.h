
#ifndef ASTAR_H
#define ASTAR_H

#include "Grid.h"
#include "Node.h"
#include <vector>

class AStar {
public:
    static std::vector<Node*> findPath(Grid& grid, Point start, Point goal);

private:
    static std::vector<Node*> reconstructPath(Node* goal);
};

#endif