
#include <xstring>

using namespace std;

class SimilarityChecker
{
public:
	int getAlphabetPoint(const string input1, const string input2)
	{
		int sameAlphabetCount = 0;
		for (char ch : input1)
		{
			for (char ch2 : input2)
			{
				if (ch == ch2)
				{
					return MAX_POINT;
				}
			}
		}

		return 0;
	}

private:
	static constexpr int MAX_POINT = 40;
};
