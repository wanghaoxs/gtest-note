#include "common.h"

class Point {
 public:
    int x, y;
    explicit Point(int x = 0, int y = 0) : x(x), y(y) {}
};

void displayPoint(const Point& p) {
    std::cout << "(" << p.x << "," << p.y << ")" << std::endl;
}

TEST(gtest, explicit) {
    //    displayPoint(1);  不支持隐式转换
    //    Point p = 1;

    displayPoint(Point(1));
    Point p(1);
}