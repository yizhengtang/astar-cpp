#include "Grid.h"
#include <iostream>
#include <array>

//THe first job, the constructor.
//This function will convert ints into Nodes.
//The idea is that it loops through my int grid and then create a node for  each cell.
//The map[i][j] == 0 part is checking if the cell is walkable (0 means walkable, 1 means obstacle).
//The reason why the Node need a default constructor is because I am creating a 2D vector of nodes, I need to initialize them first before I can assign values to them.
Grid::Grid(const std::vector<std::vector<int>>& map) {
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

//The second job, to access and bound check the grid.
//the getNode function returns a pointer to the node at the specified coordinates, or returns nullptr if the coordinates are out of bounds.

bool Grid::isInBounds(int x, int y) const {
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

Node* Grid::getNode(int x, int y) {
    if (isInBounds(x, y)) {
        return &nodes[x][y];
    }
    return nullptr;
}

//The third job, get the neighbours of a node.
//I created this function to find the neighboring nodes of a given node.
//The dx and dy arrays encode the four directions.
//After that it loops through the directions, calculates the neighbors position, and then check two things:
//1. Is it in bounds
//2. is it walkable.
//This is a very important function taht A atar will call at every step.
std::vector<Node*> Grid::getNeighbors(Node* node) {
    std::vector<Node*> neighbors;

    // 4 directions: up, down, left, right
    const std::array<int, 4> dx = { -1, 1, 0, 0 };
    const std::array<int, 4> dy = { 0, 0, -1, 1 };

    for (size_t i = 0; i < dx.size(); i++) {
        int nx = node->pos.x + dx[i];
        int ny = node->pos.y + dy[i];

        if (isInBounds(nx, ny) && nodes[nx][ny].walkable) {
            neighbors.push_back(&nodes[nx][ny]);
        }
    }

    return neighbors;
}

//Tuis last function is a display function, it prints the grid to the console.
//PrintGrid shows the terrain, printPath overlats the found path onto the grid with S for start G for goal and * for each step in between.
void Grid::printGrid() const {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (nodes[i][j].walkable) {
                std::cout << ". ";
            }
            else {
                std::cout << "# ";
            }
        }
        std::cout << std::endl;
    }
}

void Grid::printPath(const std::vector<Node*>& path) const {
    // create a character grid for display
    std::vector<std::vector<char>> display(rows, std::vector<char>(cols, '.'));

    // mark obstacles
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!nodes[i][j].walkable) {
                display[i][j] = '#';
            }
        }
    }

    // mark path
    for (auto* node : path) {
        display[node->pos.x][node->pos.y] = '*';
    }

    // mark start and goal
    if (!path.empty()) {
        display[path.front()->pos.x][path.front()->pos.y] = 'S';
        display[path.back()->pos.x][path.back()->pos.y] = 'G';
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << display[i][j] << " ";
        }
        std::cout << std::endl;
    }
}