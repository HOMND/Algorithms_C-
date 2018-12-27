#include <iostream>
#include <fstream>
#include <functional>
#include <vector>
#include <iostream>
#include <vector>

using namespace std;

long UniqueTriangles(vector<vector<long>> _triangles, long size);
bool SimilarTriangles(vector<long> t1, vector<long> t2);


bool SimilarTriangles(vector<long> t1, vector<long> t2)
{
	return ((t1[0] / t2[0] == t1[1] / t2[1]) &&
		(t1[1] / t2[1] == t1[2] / t2[2]) &&
		(t1[0] / t2[0] == t1[2] / t2[2]));
}

long UniqueTriangles(vector<vector<long>> triangles, long size)
{
	long i, j;
	long tmp;
	vector<vector<long>> Uniques;
	//сортировка сторон, для удобства сравнения (пузырек)
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < 2; j++)
		{
			if (triangles[i][j] >= triangles[i][j + 1])
			{
				tmp = triangles[i][j];
				triangles[i][j] = triangles[i][j + 1];
				triangles[i][j + 1] = tmp;
			}
		}
	}

	//индукция по уникальным треугольникам
	if (size == 0)
	{
		return 0;
	}
	else
	{
		Uniques.push_back(triangles[0]);
	}

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < Uniques.size(); j++)
		{
			if (SimilarTriangles(triangles[i], Uniques[j]))
				break;
		}
		if (j == Uniques.size())
		{
			Uniques.push_back(triangles[i]);
		}
	}

	return Uniques.size();
}

int main()
{

	triangles
	int size;
	int i, j;
	int tmp;
	vector<vector<int>> triangles;
	ifstream file1;

	file1.open("D:/input.txt");
	file1 >> size;

	for (i = 0; i < size; i++)
	{
		vector<int> triangle;
		for (j = 0; j < 3; j++)
		{
			file1 >> tmp;
			triangle.push_back(tmp);
		}
		triangles.push_back(triangle);
	}
	cout << UniqueTriangles(triangles, size);

	getch();
	return 0;
}
