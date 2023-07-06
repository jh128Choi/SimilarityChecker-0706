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

TEST_F(SimilarityCheckerFixture, 20PointWhenUsedAlphabetAreSameHalfOnTotal) {
	string input1 = "ABCD";
	string input2 = "BC";

	int point = checker.getAlphabetPoint(input1, input2);

	EXPECT_EQ(20, point);
}

TEST_F(SimilarityCheckerFixture, 20PointWhenUsedAlphabetAreSameHalfOnTotalB) {
	string input1 = "BC";
	string input2 = "ABCD";

	int point = checker.getAlphabetPoint(input1, input2);

	EXPECT_EQ(20, point);
}

TEST_F(SimilarityCheckerFixture, 20PointWhenUsedAlphabetAreSamePartialy) {
	string input1 = "ABCDEF";
	string input2 = "CDEFGH";

	int point = checker.getAlphabetPoint(input1, input2);

	EXPECT_EQ(20, point);
}