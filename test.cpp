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

int main(int argc, char* argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
	}
TEST(NormalTestSingle,TriangleTest) {
	EXPECT_EQ(Equilateral, judge_triangle(1,1,1));
	EXPECT_EQ(Equilateral, judge_triangle(2,2,2));
	EXPECT_EQ(Equilateral, judge_triangle(100,100,100));
	EXPECT_EQ(Equilateral, judge_triangle(199,199,199));
	
	EXPECT_EQ(Isosceles, judge_triangle(100,100,199));
	}

TEST(RobustTestSingle,TriangleTest) {
	EXPECT_EQ(INVALID, judge_triangle(0,0,0));

	EXPECT_EQ(Equilateral, judge_triangle(1,1,1));
	EXPECT_EQ(Equilateral, judge_triangle(2,2,2));
	EXPECT_EQ(Equilateral, judge_triangle(100,100,100));
	EXPECT_EQ(Equilateral, judge_triangle(199,199,199));
	EXPECT_EQ(INVALID, judge_triangle(200,200,200));
	
	EXPECT_EQ(Isosceles, judge_triangle(100,100,199));
	EXPECT_EQ(NotTriangle, judge_triangle(99,99,198));
	EXPECT_EQ(INVALID, judge_triangle(100,100,200)); //This is due to spec
	}
