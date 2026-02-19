#include "Point.h"
#include <cmath>

int ManhattanDistance(const Point& p1, const Point& p2) {
    return std::abs(p1.x - p2.x) + std::abs(p1.y - p2.y);
}