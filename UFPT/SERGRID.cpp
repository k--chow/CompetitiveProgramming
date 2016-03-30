#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> p;

void queueItUp(p current, deque<p>& q, vii & visited, vii graph, int m, int n)
{
    int value = graph[current.first][current.second];

    //up
    if (current.second+value < m && visited[current.first][current.second+value] == 0)
    {
        q.push_back(make_pair(current.first, current.second +value));
    }

    //down
    if (current.second-value > -1 && visited[current.first][current.second-value] == 0)
    {
        q.push_back(make_pair(current.first, current.second + value));
    }

    //left
    if (current.first-value > -1 && visited[current.first-value][current.second] == 0)
    {
        q.push_back(make_pair(current.first-value, current.second));
    }

    //right
    if (current.first+value < n && visited[current.first+value][current.second] == 0)
    {
        q.push_back(make_pair(current.first+value, current.second));
    }

}

int main()
{
    //save 2d array, -1 for parsing
    int m, n;
    cin >> m >> n;
    vii graph(m);
    for(int i=0; i<m; i++)
    {
        string s;
        cin >> s;
        for(int j=0; j<n; j++)
        {
            graph[i].push_back((int)s[j] -'0');
            //cout << (int)s[j] -'0';
        }
    }
    //save 2d array from visited
    vii visited(m);
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            visited[i].push_back(0);
        }
    }

    //start from 0,0 - set to visited
    visited[0][0] = 1;

    //do first one add to queue<pair> value of coordinate up right down left
    deque<p> q;
    p a = make_pair(0, 0);
    queueItUp(a, q, visited, graph, m, n);
    bool found = false;
    int c = 1;
    while (!q.empty())
    {
    c++;
    //pop queue as next place to visit. now set to visited
    p next = q.front();
    q.pop_front();
    visited[next.first][next.second] = 1;
    //add all possible places to queue that are unvisited
    queueItUp(next, q, visited, graph, m, n);
    //terminate if (m, n) is visited
    if (visited[n-1][m-1] == 1)
    {
        found = true;
        break;
    }
    }

    if (found)
    {
        cout << "FOUND" << endl;
        cout << c << endl;
    }
    else
    {
        cout << "NOT FOUND" << endl;
        cout << c << endl;
    }
}
