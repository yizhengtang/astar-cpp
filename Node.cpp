#include "Node.h"

Node::Node()
    : pos({ 0, 0 }), g(0), h(0), f(0), walkable(true), parent(nullptr) {
}

Node::Node(Point pos, bool walkable)
    : pos(pos), g(0), h(0), f(0), walkable(walkable), parent(nullptr) {
}

void Node::calculateF() {
    f = g + h;
}

bool Node::operator>(const Node& other) const {
    return f > other.f;
}