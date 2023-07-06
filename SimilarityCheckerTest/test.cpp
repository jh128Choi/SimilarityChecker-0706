#include "pch.h"
#include "../SimilarityChecker/SimilarityChecker.cpp"

using namespace std;

TEST(SimilarityCheckerFixture, 60PointWhenSameLength) {
	string input1 = "ABC";
	string input2 = "DEF";
	SimilarityChecker checker;
	int point = checker.getLengthPoint(input1, input2);

	EXPECT_EQ(60, point);
}

TEST(SimilarityCheckerFixture, 0PointWhenBiggerOrSameThanDoubleLength) {
	string input1 = "A";
	string input2 = "AA";
	SimilarityChecker checker;
	int point = checker.getLengthPoint(input1, input2);

	EXPECT_EQ(0, point);
}