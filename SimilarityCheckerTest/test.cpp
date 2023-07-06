#include "pch.h"
#include "../SimilarityChecker/SimilarityChecker.cpp"

using namespace std;

TEST(TestCaseName, TestName) {
	string input1 = "ABC";
	string input2 = "DEF";
	SimilarityChecker checker;
	int point = checker.getLengthPoint(input1, input2);

	EXPECT_EQ(60, point);
}