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

int SolidTeam(vector<pair<int, int>> players, int N, vector<int> &team)
{
	int i;
	int Cap, X = 0, PrevX = 0;
	int Sum = 0, NewSum = 0;
	function<bool(pair<int, int>, pair<int, int>)> Compare = MyCompare;
	vector<int> newteam;

	QuickSort::qsort(players, Compare);

	for (i = N - 1; i >= 0; i--)
	{
		Cap = i;
		PrevX = X;
		X = Weakest(players, Cap);
		newteam = team;
		NewSum = Sum;

		if (i == N - 1)
		{
			for (int j = X; j <= i; j++)
			{
				Sum += players[j].second;
				team.push_back(players[j].first);
			}
		}
		else
		{
			newteam.erase(newteam.end() - 1);
			NewSum -= players[Cap + 1].second;
			
			for (int j = PrevX; j >= X; j--)
			{
				newteam.insert(newteam.begin(), players[j].first);
				NewSum += players[j].second;
			}
			if (NewSum > Sum)
			{
				Sum = NewSum;
				team = newteam;
			}
		}
	}

	return Sum;
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

int main()
{
	int N;
	int i, j;
	vector<pair<int, int>> players;
	vector<int> team;
	ifstream file1;

	file1.open("D:/input.txt");

	file1 >> N;

	for (i = 0; i < N; i++)
	{
		pair<int, int> p;
		file1 >> p.second;
		p.first = i + 1;
		players.push_back(p);
	}

	cout << SolidTeam(players, N, team) << "\n";
	for (i = 0; i < team.size(); i++)
	{
		cout << team[i] << " ";
	}

	getch();
	return 0;
}
