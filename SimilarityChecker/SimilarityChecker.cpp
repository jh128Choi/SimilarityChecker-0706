
#include <xstring>

using namespace std;

class SimilarityChecker
{
public:
	int getLengthPoint(const string input1, const string input2)
	{
		int length1 = input1.size();
		int length2 = input2.size();

		if (isLengthDoublUp(length1, length2)) {
			return 0;
		}

		int gap = length1 < length2 ? length2 - length1 : length1 - length2;
		int shortLength = length1 > length2 ? length2 : length1;
		double rate = gap / (double)shortLength;

		return MAX - (MAX * rate);
	}

private:
	static constexpr int MAX = 60;

	bool isLengthDoublUp(int length1, int length2)
	{
		if (length1 * 2 <= length2)
		{
			return true;
		}
		if (length1 >= length2 * 2)
		{
			return true;
		}
		return false;
	}
};
