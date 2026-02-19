#include <iostream>
#include <vector>
#include "Point.h"

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

	// test Point and ManhattanDistance
	Point start = { 0, 0 };
	Point goal = { 4, 4 };
	cout << endl;
	cout << "Start: (" << start.x << ", " << start.y << ")" << endl;
	cout << "Goal:  (" << goal.x << ", " << goal.y << ")" << endl;
	cout << "Manhattan Distance: " << ManhattanDistance(start, goal) << endl;
	return 0;
}