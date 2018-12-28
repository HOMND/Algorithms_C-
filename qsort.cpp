#include <iostream>
#include <fstream>
#include <functional>
#include <iostream>
#include <vector>
#include <functional>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;
using namespace std;

int main()
{
	vector<double> TestVector;
	function<bool(double, double)> Compare = TestCompare;
	
	TestVector.push_back(1);
	TestVector.push_back(-1);
	TestVector.push_back(4);
	TestVector.push_back(3);
	TestVector.push_back(0);

	QuickSort::qsort(TestVector, Compare);

	for (int i = 0; i < TestVector.size(); i++)
	{
		cout << TestVector[i] << " ";
	}



	getch();
	return 0;
}

namespace QuickSort
{
	template < typename T >
	void qsort(vector<T> &v, function<bool(T a, T b)> Compare)
	{
		qsortInternal(v, Compare, 0, v.size() - 1);
	}

	template <typename T>
	void qsortInternal(vector<T> &v, function<bool(T a, T b)> Compare, int i1, int i2)
	{
		vector<T> v1, v2;
		T key;
		int i, ikey;
		int index11, index12, index21, index22;

		if (i2 <= i1) return;

		srand(time(NULL));
		ikey = i1 + rand() % (i2 - i1 + 1);
		key = v[ikey];

		for (i = i1; i <=i2; i++)
		{
			if (i == ikey) continue;

			if (Compare(v[i], key))
			{
				v1.push_back(v[i]);
			}
			else
			{
				v2.push_back(v[i]);
			}
		}
		
		for (i = i1; i < i1 + v1.size(); i++)
		{
			v[i] = v1[i - i1];
		}
		v[i1 + v1.size()] = key;
		for (i = i1 + v1.size() + 1; i <= i2; i++)
		{
			v[i] = v2[i - i1 - v1.size() - 1];
		}

		index11 = i1;
		index12 = i1 + v1.size() - 1;
		index21 = i1 + v1.size() + 1;
		index22 = i2;
		v1.erase(v1.begin(), v1.end());
		v2.erase(v2.begin(), v2.end());

		qsortInternal(v, Compare, index11, index12);
		qsortInternal(v, Compare, index21, index22);

	}
}
