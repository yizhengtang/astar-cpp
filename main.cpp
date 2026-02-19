#include <iostream>
#include <vector>
#include "Point.h"
#include "Node.h"


using namespace std;

int main() {
	vector<vector<int>> grid = {
		{0, 0, 0, 0, 0},
		{0, 1, 1, 1, 0},
		{0, 0, 0, 1, 0},
		{0, 1, 0, 0, 0},
		{0, 0, 0, 1, 0}
	};

	for (const auto& row : grid) {
		for (const auto& cell : row) {
			cout << cell << " ";
		}
		cout << endl;
	}

	//// test Point and ManhattanDistance
	//Point start = { 0, 0 };
	//Point goal = { 4, 4 };
	//cout << endl;
	//cout << "Start: (" << start.x << ", " << start.y << ")" << endl;
	//cout << "Goal:  (" << goal.x << ", " << goal.y << ")" << endl;
	//cout << "Manhattan Distance: " << ManhattanDistance(start, goal) << endl;

	Point start = { 0, 0 };
	Point goal = { 4, 4 };

	Node startNode(start, true);
	startNode.g = 0;
	startNode.h = ManhattanDistance(start, goal);
	startNode.calculateF();

	cout << endl;
	cout << "Start Node: (" << startNode.pos.x << ", " << startNode.pos.y << ")" << endl;
	cout << "g=" << startNode.g << " h=" << startNode.h << " f=" << startNode.f << endl;

	return 0;
}