#include "pch.h"
#include "../SimilarityChecker/SimilarityChecker.cpp"

using namespace std;

class SimilarityCheckerFixture : public testing::Test
{
public:
	SimilarityChecker checker;
};

TEST_F(SimilarityCheckerFixture, 40PointWhenSameAlphabet) {
	string input1 = "ABC";
	string input2 = "ABC";

	int point = checker.getAlphabetPoint(input1, input2);

	EXPECT_EQ(40, point);
}

TEST_F(SimilarityCheckerFixture, 40PointWhenSameAlphabetCount) {
	string input1 = "ABC";
	string input2 = "BCA";

	int point = checker.getAlphabetPoint(input1, input2);

	EXPECT_EQ(40, point);
}

TEST_F(SimilarityCheckerFixture, 0PointWhenUsedAlphabetAreDifferentAll) {
	string input1 = "ABCD";
	string input2 = "HJKL";

	int point = checker.getAlphabetPoint(input1, input2);

	EXPECT_EQ(0, point);
}