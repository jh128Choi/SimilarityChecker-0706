
#include <xstring>

using namespace std;

class SimilarityChecker
{
public:
	int getLengthPoint(const string input1, const string input2)
	{
		int length1 = input1.size();
		int length2 = input2.size();
		if (length1 * 2 <= length2)
		{
			return 0;
		}
		if (length1 >= length2 * 2)
		{
			return 0;
		}
		return 60;
	}
};
