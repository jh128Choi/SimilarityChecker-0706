#include "pch.h"
#include "../SimilarityChecker/SimilarityChecker.cpp"

using namespace std;

TEST(SimilarityChecker, 40PointWhenSameAlphabet) {
	SimilarityChecker checker;
	string input1 = "ABC";
	string input2 = "ABC";

	int point = checker.getAlphabetPoint(input1, input2);

	EXPECT_EQ(40, point);
}