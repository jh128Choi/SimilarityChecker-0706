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

TEST_F(SimilarityCheckerFixture, 0PointWhenFirstStringIsBiggerOrSameThanDoubleLength) {
	string input1 = "AA";
	string input2 = "A";

	int point = checker.getLengthPoint(input1, input2);

	EXPECT_EQ(0, point);
}

TEST_F(SimilarityCheckerFixture, 0PointWhenSecondStringIsBiggerOrSameThanDoubleLength) {
	string input1 = "B";
	string input2 = "AAA";

	int point = checker.getLengthPoint(input1, input2);
  
  EXPECT_EQ(0, point);
}
  
TEST_F(SimilarityCheckerFixture, 30PointWhenLength2And3) {
	string input1 = "BB";
	string input2 = "AAA";

	int point = checker.getLengthPoint(input1, input2);

	EXPECT_EQ(30, point);
}

TEST_F(SimilarityCheckerFixture, 20PointWhenLength3And5) {
	string input1 = "BBCCC";
	string input2 = "AAA";

	int point = checker.getLengthPoint(input1, input2);
  
  EXPECT_EQ(20, point);
}
  
TEST_F(SimilarityCheckerFixture, 40PointWhenLength3And4) {
	string input1 = "BCC";
	string input2 = "AAAD";

	int point = checker.getLengthPoint(input1, input2);

	EXPECT_EQ(40, point);
}

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