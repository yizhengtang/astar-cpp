#ifndef POINT_H
#define POINT_H

#include <iostream>

struct Point {
    int x;
    int y;

    bool operator==(const Point& rhs) const {
        return x == rhs.x && y == rhs.y;
    }

    bool operator!=(const Point& rhs) const {
        return !(*this == rhs);
    }
};

std::ostream& operator<<(std::ostream& os, const Point& p);

int ManhattanDistance(const Point& p1, const Point& p2);

#endif

