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

int GreedyRobin(int size, vector<pair<int, int>> coins);

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

int dist(int a, int b)
{
	return abs(a - b);
}

bool ComparePairs(pair<int, int> a, pair<int, int> b)
{
	return (a.first <= b.first);
}

int min(int a, int b)
{
	return ((a < b) ? a : b);
}

int GreedyRobin(int size, vector<pair<int, int>> coins)
{
	int result = 0;
	int i, j;
	int N;
	function<bool(pair<int, int>, pair<int, int>)> Compare;

	int **ans1, **ans2;

	//сортировка входного массива
	Compare = ComparePairs;

	QuickSort::qsort(coins, Compare);
	
	//Создание шкалы динамического программирования
	ans1 = new int*[size];
	ans2 = new int*[size];

	for (i = 0; i < size; i++)
	{
		ans1[i] = new int[size];
		ans2[i] = new int[size];
	}

	//Начальные условия динамического программирования
	for (i = 0; i < size; i++)
	{
		ans1[i][i] = 0;
		ans2[i][i] = 0;
	}
	//Цикл динамического программирования по двум фазовым координатам
	for (j = 1; j < size; j++)
	{
		for (i = 0; i < size - 1; i++)
		{
			if (i + j > size - 1)
				continue;
			ans1[i][i + j] = min(ans1[i + 1][i + j] + dist(coins[i].first, coins[i + 1].first),
				ans2[i + 1][i + j] + dist(coins[i].first, coins[i + j].first));
			if (ans1[i][i + j]>coins[i].second)
			{
				ans1[i][i + j] = 1e9;
			}

			ans2[i][i + j] = min(ans1[i][i + j - 1] + dist(coins[i].first, coins[i + j].first),
				ans2[i][i + j - 1] + dist(coins[i + j - 1].first, coins[i + j].first));
			if (ans2[i][i + j]>coins[i + j].second)
			{
				ans2[i][i + j] = 1e9;
			}
		}
	}


	result = min(ans1[0][size - 1], ans2[0][size - 1]);

	return ((result<1e9)?result:-1);
}

int main()
{

	int size;
	int i, j;
	int tmp;
	vector<pair<int, int>> coins;
	ifstream file1;

	file1.open("D:/input.txt");

	file1 >> size;

	for (i = 0; i < size; i++)
	{
		pair<int, int> coin;
		
		file1 >> coin.first >> coin.second;
			coins.push_back(coin);
	}

	cout << GreedyRobin(size, coins);

	getch();
	return 0;
}
