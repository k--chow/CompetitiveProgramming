#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <unordered_map>
using namespace std;

void bfs(vector< vector<int> > & list, vector<int> & visited)
{
    visited[1] = 1;
    deque<int> q;
    for(int i=0; i<list[1].size(); i++)
    {
        q.push_back(list[1][i]);
        visited[list[1][i]] = 1;
    }
    while (!q.empty())//queue isn't empty
    {
        int de = q.front();
        cout << de << endl;
        q.pop_front();

        for(int i=0; i<list[de].size(); i++)
        {
            if (visited[list[de][i]] == 0)//if unvisited
            {
                //queue it up and set as visited
                q.push_back(list[de][i]);
                visited[list[de][i]] = 1;
            }
        }
    }


    bool v = true;

    for(int i=1; i<visited.size(); i++)
    {
        if (visited[i] == 0)
        {
            v = false;
        }
        //cout << visited[i] << endl;
    }

    if (v)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> visited(n+1, 0);
    vector< vector<int> > list(n+1);

    for(int i=0; i<e; i++)
    {
        int a,b;
        cin >> a >> b;
        list[a].push_back(b);
        list[b].push_back(a);
    }

    if (e != n-1)
    {
        cout << "NO" << endl;
    }
    else //run BFS on this bih from any vertex
    {
        bfs(list, visited);

    }
}
