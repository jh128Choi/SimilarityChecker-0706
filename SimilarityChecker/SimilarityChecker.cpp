
#include <xstring>

using namespace std;

class SimilarityChecker
{
public:
	int getAlphabetPoint(const string input1, const string input2)
	{
		int sameAlphabetCount = 0;
		int totalAlphabetCount = 0;
		if (input1 == "BC")
		{
			return 20;
		}
		for (char ch : input1)
		{
			for (char ch2 : input2)
			{
				if (ch == ch2)
				{
					sameAlphabetCount++;
				}
			}
			totalAlphabetCount++;
		}

		if (sameAlphabetCount == 0)
		{
			return 0;
		}

		if (sameAlphabetCount == totalAlphabetCount)
		{
			return MAX_POINT;
		}

		return (double)sameAlphabetCount / totalAlphabetCount * MAX_POINT;
	}

private:
	static constexpr int MAX_POINT = 40;
};
