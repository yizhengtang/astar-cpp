#include "AStar.h"
#include "Point.h"
#include <queue>
#include <set>
#include <algorithm>
#include <iostream>


//First function, this is hte first algorithm in the Astar, it will find the path from start to goal.
//it starts at goal, and then it follows the parent pointers all the way back to start (where parent is nullptr)
//By doing this, it gives a path in reverse, so lastly I have to use std::reverse to flip it back to the correct order.
std::vector<Node*> AStar::reconstructPath(Node* goal) {
    std::vector<Node*> path;
    Node* current = goal;

    while (current != nullptr) {
        path.push_back(current);
        current = current->parent;
    }

    std::reverse(path.begin(), path.end());
    return path;
}

//The second function, this is the main AStar algorithm.
//it starts by getting the start and goal nodes from the grid, and then it validates them by checking if they are in bounds and walkable.

std::vector<Node*> AStar::findPath(Grid& grid, Point start, Point goal) {
    //The first thing it does is to convert the point coordinates into node pointers using the grid's getNode funciton.
    Node* startNode = grid.getNode(start.x, start.y);
    Node* goalNode = grid.getNode(goal.x, goal.y);

    //The second thing is to validate. It make sure it is not out of bounds and it is walkable.
    //if either the start or goal is invalid, it prints an error message and returns an empty path.
    if (!startNode || !goalNode) {
        std::cout << "Error: start or goal is out of bounds." << std::endl;
        return {};
    }
    if (!startNode->walkable || !goalNode->walkable) {
        std::cout << "Error: start or goal is an obstacle." << std::endl;
        return {};
    }

    // min-heap: smallest f on top
    // std::priority_queue is a max-heap by default
    // this comparator flips it — this is why we wrote operator> in Node
    //--------------------------------------------------
    //THere are three data structures here:
    //openList is the priority queue that holds the nodes that is currently being considered for exploration, and it is ordered by f value (lowest f has the highest priority).
    //openSet is a parallel set that lets us quickly check if a node is in the open list.
    //the last is the closedSet, which tracks the nodes that has finished exploring.
    //--------------------------------------------------
    auto cmp = [](Node* a, Node* b) { return a->f > b->f; };
    std::priority_queue<Node*, std::vector<Node*>, decltype(cmp)> openList(cmp);

    //here i use std::set containersto store the open and closed sets in sorted order.
    std::set<Node*> openSet;   // tracks what's in the queue (for fast lookup)
    std::set<Node*> closedSet; // tracks what's already explored

    // initialize start node
    startNode->g = 0;
    startNode->h = ManhattanDistance(startNode->pos, goalNode->pos);
    startNode->calculateF();
    startNode->parent = nullptr;

    openList.push(startNode);
    openSet.insert(startNode);

    while (!openList.empty()) {
        // pick the node with the lowest f
        Node* current = openList.top();
        openList.pop();
        openSet.erase(current);

        // goal reached — reconstruct and return the path
        if (current == goalNode) {
            return reconstructPath(goalNode);
        }

        closedSet.insert(current);

        // explore neighbors
        for (Node* neighbor : grid.getNeighbors(current)) {
            if (closedSet.count(neighbor)) {
                continue;  // already fully explored, skip
            }

            int tentativeG = current->g + 1;  // each step costs 1

            if (!openSet.count(neighbor) || tentativeG < neighbor->g) {
                neighbor->parent = current;
                neighbor->g = tentativeG;
                neighbor->h = ManhattanDistance(neighbor->pos, goalNode->pos);
                neighbor->calculateF();

                if (!openSet.count(neighbor)) {
                    openList.push(neighbor);
                    openSet.insert(neighbor);
                }
            }
        }
    }
}