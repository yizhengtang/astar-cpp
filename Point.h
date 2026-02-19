#ifndef POINT_H
#define POINT_H

#include <cmath>

struct Point {
    int x;
    int y;
};

int ManhattanDistance(const Point& p1, const Point& p2);

#endif

