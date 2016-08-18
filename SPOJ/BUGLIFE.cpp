#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
using namespace std;
vector< vector<int> > matrix(2010);
vector<int> visited(2010, 0);


int h;
int a;
void dfs(int previous, int current, int nodeCount)//use a count
{
	visited[current] = nodeCount;
	//visited and not parent = cycle
	for(int i=0; i<matrix[current].size(); i++)
	{
			int neighbor = matrix[current][i];
			if (visited[neighbor] == 0)
			{
				dfs(current, neighbor, nodeCount+1);
			}
			else if(neighbor != previous)//visited and not parent
			{
				//cycle exists, count how many nodes are involved
				//use visited array as nodeCount
				if ((nodeCount+1 - visited[neighbor]) % 2 != 0)
				{
					h = 1; //cycle exists
				}	
				
			}
		
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); //is it this?
	int s=1;
	int N;
	cin >> N;
	for(int i=0; i<N; i++)
	{
		int b; //a number of nodes
		cin >> a >> b; //b is interactions
		h = 0;

		for(int r=0; r<a; r++)
		{
			matrix[r].clear();
			visited[r] = 0;
		}

		int q, w;
		for(int j=0; j<b; j++)
		{
			
			cin >> q >> w;
			matrix[q-1].push_back(w-1);
			matrix[w-1].push_back(q-1);
		}
		//dfs
		for(int j=0; j<a; j++)
		{
			if (visited[j] == 0)
			{
				dfs(-1, j, 1);
			}
		}
		
		cout << "Scenario #" << s  <<":"<< endl;
		if (h)
		{
			cout << "Suspicious bugs found!" << endl;
		}
		else
		{
			cout << "No suspicious bugs found!" << endl;
		}
		s++;
	}

}