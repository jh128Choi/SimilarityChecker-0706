
#include <vector>
#include <xstring>

using namespace std;

class SimilarityChecker
{
public:
	int getAlphabetPoint(const string input1, const string input2)
	{
		vector<char> usedCharList1 =  getUsedAlphabetList(input1);
		vector<char> usedCharList2 = getUsedAlphabetList(input2);

		int sameAlphabetCount = getSameAlphabetCount(usedCharList1, usedCharList2);
		int totalAlphabetCount = getTotalUsedAlphabetCount(usedCharList1, usedCharList2, sameAlphabetCount);

		if (isAllDifferentUsedAlphabetCount(sameAlphabetCount))
		{
			return MIN_POINT;
		}

		if (isSameUsedAlphabetCount(sameAlphabetCount, totalAlphabetCount))
		{
			return MAX_POINT;
		}

		return getPartialPoint(sameAlphabetCount, totalAlphabetCount);
	}

private:
	static constexpr int MAX_POINT = 40;
	static constexpr int MIN_POINT = 0;

	vector<char> getUsedAlphabetList(const string input)
	{
		vector<char> usedCharLIst;
		for (char ch : input)
		{
			bool found = false;
			for (char used : usedCharLIst)
			{
				if (ch == used)
				{
					found = true;
					break;
				}
			}
			if (!found)
			{
				usedCharLIst.push_back(ch);
			}
		}
		return usedCharLIst;
	}

	int getSameAlphabetCount(vector<char> usedCharList1, vector<char> usedCharList2)
	{
		int sameAlphabetCount = 0;
		for (char ch1 : usedCharList1)
		{
			for (char ch2 : usedCharList2)
			{
				if (ch1 == ch2)
				{
					sameAlphabetCount++;
					break;
				}
			}
		}
		return sameAlphabetCount;
	}

	int getTotalUsedAlphabetCount(vector<char> usedCharList1, vector<char> usedCharList2, int sameAlphabetCount)
	{
		return usedCharList1.size() + usedCharList2.size() - sameAlphabetCount;
	}

	bool isAllDifferentUsedAlphabetCount(int sameAlphabetCount)
	{
		return sameAlphabetCount == 0;
	}

	bool isSameUsedAlphabetCount(int sameAlphabetCount, int totalAlphabetCount)
	{
		return sameAlphabetCount == totalAlphabetCount;
	}

	double getPartialPoint(int sameAlphabetCount, int totalAlphabetCount)
	{
		return (double)sameAlphabetCount / totalAlphabetCount * MAX_POINT;
	}

};
