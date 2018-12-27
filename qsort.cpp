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
	template <typename T>
	void qsort(vector<T> &v, function<bool(T a, T b)> Compare)
	{
		vector<T> v1, v2;
		T key;
		int i, ikey;

		if (v.size() <= 1) return;

		srand(time(NULL));
		ikey = rand() % v.size();
		key = v[ikey];

		for (i = 0; i < v.size(); i++)
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
		qsort(v1, Compare);
		qsort(v2, Compare);

		for (i = 0; i < v1.size(); i++)
		{
			v[i] = v1[i];
		}
		v[i] = key;
		for (i = 0; i < v2.size(); i++)
		{
			v[v1.size() + i + 1] = v2[i];
		}
	}
}
