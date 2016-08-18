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
#include <queue>
using namespace std;
vector< vector<int> > matrix(2010);
vector<int> visited(2010, 0);//was it this? No
queue<int> q;
int n;
bool bi;

//out of ideas as to why TLE

void bfs(int current)
{
	//visited[i] = color*-1;

	for(int i=0; i<matrix[current].size(); i++)
		{
			//if unvisited, add to queue
				if (visited[matrix[current][i]] == 0)
				{
					q.push(matrix[current][i]);//fix 2, No
					visited[matrix[current][i]] = visited[current]* (-1);
					
				}
				else
				{
					if (visited[matrix[current][i]] == visited[current]) {
						bi = true;
						return;
					}
				}
				
			
			

			//if visited, check that they are color*-1
		}
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); //is it this?
	int cases;
	cin >> cases;
	int a, b;

	for(int i=0; i<cases; i++)
	{

		bi = false;
		int in;
		cin >> n >> in;
		for(int j=0; j<n; j++)
		{
			matrix[j].clear();
			visited[j] = 0;
		}
		

		for(int j=0; j<in; j++)
		{
			cin >> a >> b;
			matrix[a-1].push_back(b-1);
			matrix[b-1].push_back(a-1);
		}
		//bfs on every node
	//q push first
	int color = 1;

	for(int j=0; j<n; j++)
	{
		if (visited[j] == 0)
		{
			q.push(j);
			visited[j] = color;
		}
		
		while (!q.empty())
		{
			int current = q.front();
			q.pop();
			bfs(current);
		}
		if (bi) {
			while (!q.empty()) q.pop();//was it this?
			break;
		}

	}


		cout << "Scenario #" << i+1 << ":" << endl;
		if (bi) {
			cout << "Suspicious bugs found!" << endl;
		} else {
			cout << "No suspicious bugs found!" << endl;
		}
	}

}