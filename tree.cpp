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

struct node
{
	int element;
	node *left;
	node *right;
	int height;
};

typedef struct node *nodeptr;

class AVLTree
{
public:
	void insert(int, nodeptr &);
	void erase(int, nodeptr &);
	void print(nodeptr);

	int height(nodeptr);
	nodeptr srl(nodeptr &);
	nodeptr drl(nodeptr &);
	nodeptr srr(nodeptr &);
	nodeptr drr(nodeptr &);
	int deletemin(nodeptr &);
};

int max(int value1, int value2)
{
	return ((value1 > value2) ? value1 : value2);
}

void AVLTree::insert(int x, nodeptr &p)
{
	if (p == NULL)
	{
		p = new node;
		p->element = x;
		p->left = NULL;
		p->right = NULL;
		p->height = 0;
		if (p == NULL)
		{
			cout << "Out of Space\n";
		}
	}
	else
	{
		if (x < p->element)
		{
			insert(x, p->left);
			if ((height(p->left) - height(p->right)) == 2)
			{
				if (x < p->left->element)
				{
					p = srl(p);
				}
				else
				{
					p = drl(p);
				}
			}
		}
		else if (x > p->element)
		{
			insert(x, p->right);
			if ((height(p->right) - height(p->left)) == 2)
			{
				if (x > p->right->element)
				{
					p = srr(p);
				}
				else
				{
					p = drr(p);
				}
			}
		}
		else
		{
			cout << "Элемет существует\n";
		}
	}
	int m, n, d;
	m = height(p->left);
	n = height(p->right);
	d = max(m, n);
	p->height = d + 1;
}

void AVLTree::erase(int x, nodeptr &p)
{
	nodeptr d;
	if (p == NULL)
	{
		cout << "элемента нет\n";
	}
	else if (x < p->element)
	{
		erase(x, p->left);
	}
	else if (x > p->element)
	{
		erase(x, p->right);
	}
	else if ((p->left == NULL) && (p->right == NULL))
	{
		d = p;
		free(d);
		p = NULL;
		cout << "Элемент удален\n";
	}
	else if (p->left == NULL)
	{
		d = p;
		free(d);
		p = p->right;
		cout << "Элемент удален\n";
	}
	else if (p->right == NULL)
	{
		d = p;
		p = p->left;
		free(d);
		cout << "Элемент удален\n";
	}
	else
	{
		p->element = deletemin(p->right);
	}
}

int AVLTree::deletemin(nodeptr &p)
{
	int c;

	if (p->left == NULL)
	{
		c = p->element;
		p = p->right;
		return c;
	}
	else
	{
		c = deletemin(p->left);
		return c;
	}
}

// Печать
void AVLTree::print(nodeptr p)
{
	if (p != NULL)
	{
		print(p->left);
		cout << p->element << "\t";
		print(p->right);
	}
}

int AVLTree::height(nodeptr p)
{
	int t;
	if (p == NULL)
	{
		return -1;
	}
	else
	{
		t = p->height;
		return t;
	}
}

nodeptr AVLTree::srl(nodeptr &p1)
{
	nodeptr p2;
	p2 = p1->left;
	p1->left = p2->right;
	p2->right = p1;
	p1->height = max(height(p1->left), height(p1->right)) + 1;
	p2->height = max(height(p2->left), p1->height) + 1;
	return p2;
}
nodeptr AVLTree::srr(nodeptr &p1)
{
	nodeptr p2;
	p2 = p1->right;
	p1->right = p2->left;
	p2->left = p1;
	p1->height = max(height(p1->left), height(p1->right)) + 1;
	p2->height = max(p1->height, height(p2->right)) + 1;
	return p2;
}
nodeptr AVLTree::drl(nodeptr &p1)
{
	p1->left = srr(p1->left);
	return srl(p1);
}
nodeptr AVLTree::drr(nodeptr &p1)
{
	p1->right = srl(p1->right);
	return srr(p1);
}
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
