#include <gtest/gtest.h>
#include "triangle.h"

// Test cases :
// Normal Tests
//   including bondary values, single/multiple invalid
// Robust Tests
//   including rejecting values, single/multiple invalid

//const unsigned int normalVars[] = {1,2,100,199,200};
//const unsigned int robustVars[] = {0,1,2,100,199,200,201};

//#define NUM_NORM 5
//#define NUM_ROBU 6

int main(int argc, char *argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/* Testing Code */
// Weak Robust test for check_triangle_type()
// SideLength1to199
// SideLength0or200
// SideLengthTriInequalityNormal
// SideLengthTriInequalityRobust

// triangle boundary value of 0 ~ 200: {0, 1, 2, 110, 198, 199, 200}
TEST(CheckTriangleTypeTest, SideLength1to199){
    // all normal
    EXPECT_EQ(Equilateral, judge_triangle(110, 110, 110));
    EXPECT_EQ(Isosceles, judge_triangle(150, 150, 110));
    EXPECT_EQ(Scalene, judge_triangle(110, 113, 116));

    // one boundary and others normal
    EXPECT_EQ(Isosceles, judge_triangle(1, 110, 110));
    EXPECT_EQ(Isosceles, judge_triangle(2, 110, 110));
    EXPECT_EQ(Isosceles, judge_triangle(198, 110, 110));
    EXPECT_EQ(Isosceles, judge_triangle(199, 110, 110));

    EXPECT_EQ(Isosceles, judge_triangle(110, 1, 110));
    EXPECT_EQ(Isosceles, judge_triangle(110, 2, 110));
    EXPECT_EQ(Isosceles, judge_triangle(110, 198, 110));
    EXPECT_EQ(Isosceles, judge_triangle(110, 199, 110));

    EXPECT_EQ(Isosceles, judge_triangle(110, 110, 1));
    EXPECT_EQ(Isosceles, judge_triangle(110, 110, 2));
    EXPECT_EQ(Isosceles, judge_triangle(110, 110, 198));
    EXPECT_EQ(Isosceles, judge_triangle(110, 110, 199));
}

TEST(CheckTriangleTypeTest, SideLength0or200){
    EXPECT_EQ(INVALID, judge_triangle(0, 110, 110));
    EXPECT_EQ(INVALID, judge_triangle(200, 110, 110));

    EXPECT_EQ(INVALID, judge_triangle(110, 0, 110));
    EXPECT_EQ(INVALID, judge_triangle(110, 200, 110));

    EXPECT_EQ(INVALID, judge_triangle(110, 110, 0));
    EXPECT_EQ(INVALID, judge_triangle(110, 110, 200));
}

// triangle boundary value of a < b+c, b < a+c, c < a+b: { a = b+c, a = b+c-1, a = b+c-2, a < b+c }
TEST(CheckTriangleTypeTest, SideLengthTriInequalityNormal){
    EXPECT_EQ(Scalene, judge_triangle(100, 75, 50));
    EXPECT_EQ(Scalene, judge_triangle(100, 52, 50));
    EXPECT_EQ(Scalene, judge_triangle(100, 51, 50));

    EXPECT_EQ(Scalene, judge_triangle(75, 100, 50));
    EXPECT_EQ(Scalene, judge_triangle(52, 100, 50));
    EXPECT_EQ(Scalene, judge_triangle(51, 100, 50));

    EXPECT_EQ(Scalene, judge_triangle(75, 50, 100));
    EXPECT_EQ(Scalene, judge_triangle(52, 50, 100));
    EXPECT_EQ(Scalene, judge_triangle(51, 50, 100));
}

TEST(CheckTriangleTypeTest, SideLengthTriInequalityRobust){
    EXPECT_EQ(NotTriangle, judge_triangle(100, 50, 50));
    EXPECT_EQ(NotTriangle, judge_triangle(50, 100, 50));
    EXPECT_EQ(NotTriangle, judge_triangle(50, 50, 100));
}
