#include "pch.h"
#include "../SimilarityChecker/SimilarityChecker.cpp"

using namespace std;

class SimilarityCheckerFixture : public testing::Test
{
public:
	SimilarityChecker checker;
};

TEST_F(SimilarityCheckerFixture, 60PointWhenSameLength) {
	string input1 = "ABC";
	string input2 = "DEF";

	int point = checker.getLengthPoint(input1, input2);

	EXPECT_EQ(60, point);
}

TEST_F(SimilarityCheckerFixture, 0PointWhenAIsBiggerOrSameThanDoubleLength) {
	string input1 = "A";
	string input2 = "AA";

	int point = checker.getLengthPoint(input1, input2);

	EXPECT_EQ(0, point);
}

TEST_F(SimilarityCheckerFixture, 0PointWhenBIsBiggerOrSameThanDoubleLength) {
	string input1 = "BBB";
	string input2 = "A";

	int point = checker.getLengthPoint(input1, input2);

	EXPECT_EQ(0, point);
}