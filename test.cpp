#include <gtest/gtest.h>
#include "next_date.h"

// Test cases :
// Normal Tests
//   including bondary values, single/multiple invalid
//   e.g. 2015/12/31;2015/2/27 ...etc
// Robust Tests
//   including rejecting values, single/multiple invalid
//   e.g. 2015/12/32;2015/2/29 ...etc
//   (Regaring 0/0/0 as invalid date)

int main(int argc, char* argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
	}

TEST(TomorrowNormal,TomorrowTest) {

	Date D1 = Date(2009,1,2);
	EXPECT_EQ(D1, next_date(2009,1,1));

	Date D2 = Date(2009,2,1);
	EXPECT_EQ(D2, next_date(2009,1,31));

	Date D3 = Date(2009,1,1);
	EXPECT_EQ(D3, next_date(2008,12,31));

	Date D4 = Date(2012,2,28);
	EXPECT_EQ(D4, next_date(2012,2,27));

	Date D5 = Date(2012,2,29);
	EXPECT_EQ(D5, next_date(2012,2,28));

	}

TEST(TomorrowRobust,TomorrowTest) {
	Date D1 = Date();
	EXPECT_EQ(D1, next_date(2013,1,1));
	// Spec asked for it...

	Date D2 = Date();
	EXPECT_EQ(D2, next_date(2011,2,29));
	// 2011 is not a leap year
	}
