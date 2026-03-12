//#include <iostream>
//#include <vector>
//#include "Point.h"
//#include "Node.h"
//#include "Grid.h"
//
//
//using namespace std;
//
//int main() {
//	//vector<vector<int>> grid = {
//	//	{0, 0, 0, 0, 0},
//	//	{0, 1, 1, 1, 0},
//	//	{0, 0, 0, 1, 0},
//	//	{0, 1, 0, 0, 0},
//	//	{0, 0, 0, 1, 0}
//	//};
//
//	//for (const auto& row : grid) {
//	//	for (const auto& cell : row) {
//	//		cout << cell << " ";
//	//	}
//	//	cout << endl;
//	//}
//
//	////// test Point and ManhattanDistance
//	////Point start = { 0, 0 };
//	////Point goal = { 4, 4 };
//	////cout << endl;
//	////cout << "Start: (" << start.x << ", " << start.y << ")" << endl;
//	////cout << "Goal:  (" << goal.x << ", " << goal.y << ")" << endl;
//	////cout << "Manhattan Distance: " << ManhattanDistance(start, goal) << endl;
//
//	//Point start = { 0, 0 };
//	//Point goal = { 4, 4 };
//
//	//Node startNode(start, true);
//	//startNode.g = 0;
//	//startNode.h = ManhattanDistance(start, goal);
//	//startNode.calculateF();
//
//	//cout << endl;
//	//cout << "Start Node: (" << startNode.pos.x << ", " << startNode.pos.y << ")" << endl;
//	//cout << "Goal Node: (" << goal.x << ", " << goal.y << ")" << endl;
//	//cout << "Walkable: " << (startNode.walkable ? "Yes" : "No") << endl;
//	//cout << "g=" << startNode.g << " h=" << startNode.h << " f=" << startNode.f << endl;
//
//
//
//	vector<vector<int>> map = {
//		{0, 0, 0, 0, 0},
//		{0, 1, 1, 1, 0},
//		{0, 0, 0, 1, 0},
//		{0, 1, 0, 0, 0},
//		{0, 0, 0, 1, 0}
//	};
//
//	Grid grid(map);
//
//	cout << "=== Grid ===" << endl;
//	grid.printGrid();
//
//	// test getNode
//	cout << endl;
//	Node* node = grid.getNode(2, 2);
//	cout << "Node at (2,2): walkable=" << (node->walkable ? "yes" : "no") << endl;
//
//	Node* wall = grid.getNode(1, 1);
//	cout << "Node at (1,1): walkable=" << (wall->walkable ? "yes" : "no") << endl;
//
//	// test getNeighbors
//	cout << endl;
//	cout << "Neighbors of (2,2):" << endl;
//	for (auto* neighbor : grid.getNeighbors(node)) {
//		cout << "  (" << neighbor->pos.x << ", " << neighbor->pos.y << ")" << endl;
//	}
//
//
//	return 0;
//}


#include <iostream>
#include <vector>
#include "Grid.h"
#include "AStar.h"

using namespace std;

int main() {
    vector<vector<int>> map = {
        {0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 0, 1, 1},
        {0, 0, 0, 0, 0}
    };

    Grid grid(map);

    cout << "=== Grid ===" << endl;
    grid.printGrid();
    cout << endl;

    Point start = { 0, 0 };
    Point goal = { 4, 4 };

    cout << "Finding path from (" << start.x << "," << start.y
        << ") to (" << goal.x << "," << goal.y << ")..." << endl << endl;

    vector<Node*> path = AStar::findPath(grid, start, goal);

    if (!path.empty()) {
        cout << "=== Path Found (" << path.size() << " steps) ===" << endl;
        grid.printPath(path);

        cout << endl << "=== Step-by-step ===" << endl;
        for (auto* node : path) {
            cout << "(" << node->pos.x << ", " << node->pos.y
                << ") [f=" << node->f << " g=" << node->g << " h=" << node->h << "]"
                << endl;
        }
    }

    return 0;
}