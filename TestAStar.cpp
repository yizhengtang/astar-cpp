#include <iostream>
#include <vector>
#include "TestAStar.h"
#include "Grid.h"
#include "AStar.h"

void RunTests() {
    //TestBasicPath();
    //TestNoPath();
    TestStartIsGoal();
    TestOutOfBounds();
    TestStartOnObstacle();
    TestGoalOnObstacle();
    TestLargerGrid();
}

void TestBasicPath() {
    std::cout << "***** Test Basic Path *****" << std::endl;

    std::vector<std::vector<int>> map = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0}
    };

    Grid grid(map);
    grid.printGrid();

    Point start = { 0, 0 };
    Point goal = { 4, 4 };

    std::cout << "Start: (" << start.x << ", " << start.y << ")" << std::endl;
    std::cout << "Goal: (" << goal.x << ", " << goal.y << ")" << std::endl;

    std::vector<Node*> path = AStar::findPath(grid, start, goal);

    if (!path.empty()) {
        std::cout << "Path found with " << path.size() << " steps" << std::endl;
        grid.printPath(path);
		grid.printSteps(path);
    }
    else {
        std::cout << "FAIL: Expected a path but got none" << std::endl;
    }

    std::cout << std::endl;
}

void TestNoPath() {
    std::cout << "***** Test No Path *****" << std::endl;

    std::vector<std::vector<int>> map = {
        {0, 0, 0},
        {1, 1, 1},
        {0, 0, 0}
    };

    Grid grid(map);
    grid.printGrid();

    Point start = { 0, 0 };
    Point goal = { 2, 2 };

    std::cout << "Start: (" << start.x << ", " << start.y << ")" << std::endl;
    std::cout << "Goal: (" << goal.x << ", " << goal.y << ")" << std::endl;

    std::vector<Node*> path = AStar::findPath(grid, start, goal);

    if (path.empty()) {
        std::cout << "PASS: No path found as expected" << std::endl;
    }
    else {
        std::cout << "FAIL: Found a path when none should exist" << std::endl;
    }

    std::cout << std::endl;
}

void TestStartIsGoal() {
    std::cout << "***** Test Start Is Goal *****" << std::endl;

    std::vector<std::vector<int>> map = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    Grid grid(map);
    grid.printGrid();

    Point start = { 0, 0 };
    Point goal = { 0, 0 };

    std::cout << "Start: (" << start.x << ", " << start.y << ")" << std::endl;
    std::cout << "Goal: (" << goal.x << ", " << goal.y << ")" << std::endl;

    std::vector<Node*> path = AStar::findPath(grid, start, goal);

    if (path.size() == 1) {
        std::cout << "PASS: Path is just the start node" << std::endl;
    }
    else {
        std::cout << "FAIL: Expected 1 step, got " << path.size() << std::endl;
    }

    std::cout << std::endl;
}

void TestOutOfBounds() {
    std::cout << "***** Test Out of Bounds *****" << std::endl;

    std::vector<std::vector<int>> map = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    Grid grid(map);
    grid.printGrid();

    Point start = { 0, 0 };
    Point goal = { 5, 5 };  // way outside the 3x3 grid

    std::cout << "Start: (" << start.x << ", " << start.y << ")" << std::endl;
    std::cout << "Goal: (" << goal.x << ", " << goal.y << ")" << std::endl;

    std::vector<Node*> path = AStar::findPath(grid, start, goal);

    if (path.empty()) {
        std::cout << "PASS: Correctly rejected out of bounds goal" << std::endl;
    }
    else {
        std::cout << "FAIL: Should not find a path to out of bounds" << std::endl;
    }

    std::cout << std::endl;
}

void TestStartOnObstacle() {
    std::cout << "***** Test Start On Obstacle *****" << std::endl;

    std::vector<std::vector<int>> map = {
        {1, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    Grid grid(map);
    grid.printGrid();

    Point start = { 0, 0 };  // this is an obstacle
    Point goal = { 2, 2 };

    std::cout << "Start: (" << start.x << ", " << start.y << ")" << std::endl;
    std::cout << "Goal: (" << goal.x << ", " << goal.y << ")" << std::endl;

    std::vector<Node*> path = AStar::findPath(grid, start, goal);

    if (path.empty()) {
        std::cout << "PASS: Correctly rejected start on obstacle" << std::endl;
    }
    else {
        std::cout << "FAIL: Should not pathfind from an obstacle" << std::endl;
    }

    std::cout << std::endl;
}

void TestGoalOnObstacle() {
    std::cout << "***** Test Goal On Obstacle *****" << std::endl;

    std::vector<std::vector<int>> map = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 1}
    };

    Grid grid(map);
    grid.printGrid();

    Point start = { 0, 0 };
    Point goal = { 2, 2 };  // this is an obstacle

    std::cout << "Start: (" << start.x << ", " << start.y << ")" << std::endl;
    std::cout << "Goal: (" << goal.x << ", " << goal.y << ")" << std::endl;

    std::vector<Node*> path = AStar::findPath(grid, start, goal);

    if (path.empty()) {
        std::cout << "PASS: Correctly rejected goal on obstacle" << std::endl;
    }
    else {
        std::cout << "FAIL: Should not pathfind to an obstacle" << std::endl;
    }

    std::cout << std::endl;
}

void TestLargerGrid() {
    std::cout << "***** Test Larger Grid *****" << std::endl;

    std::vector<std::vector<int>> map = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 1, 1, 0, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 0, 1, 1, 1, 1, 1, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    Grid grid(map);
    grid.printGrid();

    Point start = { 0, 0 };
    Point goal = { 9, 9 };

    std::cout << "Start: (" << start.x << ", " << start.y << ")" << std::endl;
    std::cout << "Goal: (" << goal.x << ", " << goal.y << ")" << std::endl;

    std::vector<Node*> path = AStar::findPath(grid, start, goal);

    if (!path.empty()) {
        std::cout << "Path found with " << path.size() << " steps" << std::endl;
        grid.printPath(path);
		grid.printSteps(path);
    }
    else {
        std::cout << "FAIL: Expected a path but got none" << std::endl;
    }

    std::cout << std::endl;
}