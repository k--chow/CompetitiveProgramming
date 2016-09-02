#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
class UnionFind
{
private:
	vector<int> rank, parent;
public:
	UnionFind(int N)
	{
		for(int i=0; i<N; i++)
		{
			rank.push_back(0);
			parent.push_back(i+1);
		}
	}
	bool isSameSet(int a, int b)
	{
		return findSet(a) == findSet(b);
	}

	int findSet(int query)
	{
		if (parent[query] == query)
		{
			return query;
		}
		return parent[query] = findSet(parent[query]);
	}

	void unionSet(int i, int j)
	{
		//find parents and get ranks
		int parentI = findSet(i);
		int parentJ = findSet(j);
		if (rank[parentI] > rank[parentJ])
		{
			parent[parentJ] = parentI;
		}
		else if (rank[parentJ] > rank[parentI])
		{
			parent[parentI] = parentJ;

		}
		else
		{
			parent[parentI] = parentJ;
			rank[parentJ++];
		}
		//set parent to it
	}

};

int main()
{	
	int cases;
	cin >> cases;
	for(int i=0; i<cases; i++)
	{
		string line;
		getline(cin, line);
		if (!isdigit(line[2]))
		{
			
		}
	}
	

}