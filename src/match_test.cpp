#include <match.h>
#include <gtest/gtest.h>

struct Point {
  int x_, y_;

  constexpr Point(int x, int y) : x_(x), y_(y) {};

  Point(const Point& other) {
    std::cout << "copy ctor called" << std::endl;
    x_ = other.x_;
    y_ = other.y_;
  }

  Point(const Point&& other) {
    std::cout << "move ctor called" << std::endl;
    x_ = other.x_;
    y_ = other.y_;
  }

};

TEST(match, ints) {
    EXPECT_EQ(getIndexOfFirstMatch([](int x) { return (x > 3); }, 1, 1, 2), -1);
    EXPECT_EQ(getIndexOfFirstMatch([](int x) { return (x > 3); }, 1, 1, 5), 2);
}

TEST(match, points) {
    EXPECT_EQ(
        getIndexOfFirstMatch([](Point p) { return (p.x_ > 3); },
                            Point(1, 1), Point(1, 2), Point(1, 3)),
        -1);
        EXPECT_EQ(
        getIndexOfFirstMatch([](Point p) { return (p.x_ > 3); },
                            Point(4, 1), Point(1, 2), Point(1, 3)),
        0);
}




