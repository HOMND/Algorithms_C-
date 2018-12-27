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

int SolidTeam(vector<pair<int, int>> players, int N, vector<int> &team);

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
