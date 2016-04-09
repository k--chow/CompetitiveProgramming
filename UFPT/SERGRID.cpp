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
    //cout << "Current: " << current.first << " " << current.second << " " << value << endl;

    //up
    if (current.first+value < m && visited[current.first+value][current.second] == 0)
    {
        q.push_back(make_pair(current.first +value, current.second));
        //cout << current.first+value << " " << current.second<< endl;
        /*
        if (dist[current.first][current.second] + 1 < dist[current.first, current.second+value])
        {
            //smell trouble but try it, maybe if not less dont queue it
            dist[current.first][current.second+value] = dist[current.first][current.second] + 1;
        }*/
    }

    //down
    if (current.first-value > -1 && visited[current.first-value][current.second] == 0)
    {
        q.push_back(make_pair(current.first - value, current.second));
        // cout << current.first-value << " " << current.second << endl;
        /*
        if (dist[current.first][current.second] + 1 < dist[current.first, current.second-value])
        {
            //smell trouble but try it, maybe if not less dont queue it
            dist[current.first][current.second+value] = dist[current.first][current.second] + 1;
        }*/
    }

    //left
    if (current.second-value > -1 && visited[current.first][current.second-value] == 0)
    {
        q.push_back(make_pair(current.first, current.second-value));
         //cout << current.first << " " << current.second-value << endl;
    }

    //right
    if (current.second+value < n && visited[current.first][current.second+value] == 0)
    {
        q.push_back(make_pair(current.first, current.second+value));
         //cout << current.first << " " << current.second+value << endl;
    }



}

int main()
{
    //save 2d array, -1 for parsing
    int m, n;
    cin >> m >> n;
    //cout << "y " << m << "x " << n << endl;
    vii graph(m);
    vii visited(m);
    for(int i=0; i<m; i++)
    {
        string s;
        cin >> s;
        for(int j=0; j<n; j++)
        {
            graph[i].push_back((int)s[j] -'0');
            visited[i].push_back(0);
            //cout << graph[i][j] << " ";
        }
        //cout << endl;
    }
    //cout << "part " << graph[2][0] << endl;
    //save 2d array from visited


    //start from 0,0 - set to visited
    visited[0][0] = 1;
    //dist[0][0] = 0;

    //do first one add to queue<pair> value of coordinate up right down left
    deque<p> q;
    p a = make_pair(0, 0);
    queueItUp(a, q, visited, graph, m, n);
    bool found = false;
    int counter = 2; //2 because 1 is 0
    int scounter = 0;
    int s = q.size();

    while (!q.empty())
    {
    //cout << "hi" << endl;
    //pop queue as next place to visit. now set to visited
    p next = q.front();
    q.pop_front();
    scounter++;
    visited[next.first][next.second] = counter;
    //visited[next.first][next.second] = 1;
    //add all possible places to queue that are unvisited
    queueItUp(next, q, visited, graph, m, n);
    //terminate if (m, n) is visited
    if (scounter == s)
    {
        counter++;
        scounter = 0;
        s = q.size();
    }

    if (visited[m-1][n-1] != 0)
    {
        found = true;
        break;
    }

    }

    if (found)
    {
        cout << counter-1 << endl;
    }
    else
    {
        cout << IMPOSSIBLE << endl;
    }

}
