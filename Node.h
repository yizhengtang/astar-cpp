#ifndef NODE_H
#define NODE_H

#include "Point.h"

class Node {
public:
    Point pos;
    int g;             // cost from start to this node
    int h;             // heuristic (estimated cost to goal)
    int f;             // total cost: g + h + cost
	int cost;          // terrain cost
    bool walkable;
    Node* parent;

    Node();
    //I added a new parameter to the constructor which is the cost of movement in the terrain, the = 1 means that if the cost is not specified it will be 1.
    Node(Point pos, bool walkable, int cost = 1);

    void calculateF();

    bool operator>(const Node& other) const;
};

#endif
