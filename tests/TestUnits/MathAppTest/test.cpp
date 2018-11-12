#include "pch.h"
#include "../TestUnits/doubleNum.cpp"

TEST(DoubleNumTest, positiveValues) {
	ASSERT_EQ(12, doubleNum(6));
	ASSERT_EQ(4, doubleNum(2));
	ASSERT_EQ(10, doubleNum(5));
	ASSERT_EQ(16, doubleNum(8));
}

TEST(DoubleNumTest, negativeValues) {
	ASSERT_EQ(12, doubleNum(-6));
	ASSERT_EQ(-4, doubleNum(-2));
	ASSERT_EQ(-10, doubleNum(-5));
	ASSERT_EQ(-16, doubleNum(-8));
}