

#include <algorithm>
#include <vector>
#include <tuple>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <queue>
#include <unordered_map>
#include <map>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> p;
typedef pair< vector<int>, int> p2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m, n;
    cin >> m >> n;
    vector<string> arr;
    vector<string> visited;
    string pl = "0";
    while (pl.length() != n)
    {
        pl+="0";
    }

    for(int i=0; i<m; i++)
    {
        string a;
        cin >> a;
        arr.push_back(a);//array as string now
        //cout << arr.at(i) << endl;
        visited.push_back(pl);
        //cout << pl << endl;
    }
    //stored

    //start from 0, 0
    queue<p> q;
    visited[0][0] = 1;
    int level = 1;
    int neighbors = 0;

    p test = make_pair(0, 0); //y x
    //queue up nodes

    int value = arr[0][0] - 48;
    //cout << value << endl;
    //up
    if (test.first - value >= 0 && (int)visited[test.first - value][test.second] - 48 == 0)
    {
        q.push(make_pair(test.first -value, test.second));
        neighbors++;
    }
    //down
    if (test.first + value < m && (int)visited[test.first + value][test.second] - 48 == 0)
    {
        q.push(make_pair(test.first + value, test.second));
        neighbors++;
    }
    //left
    if (test.second - value >= 0 && (int)visited[test.first][test.second - value] - 48 == 0)
    {
        q.push(make_pair(test.first, test.second - value));
         neighbors++;
    }
    //right
    if (test.second + value < n && (int)visited[test.first][test.second + value] - 48 == 0)
    {
        q.push(make_pair(test.first, test.second + value));
         neighbors++;
    }

    bool found = false;
    int newNeighbors = 0;
    while (!q.empty())
    {
        p newPair = make_pair(q.front().first, q.front().second);
        //cout << "newPair " << newPair.first << " " << newPair.second << endl;
        q.pop();
        value = (int)arr[newPair.first][newPair.second] - 48;
        visited[newPair.first][newPair.second] = 1;
        //set neighbors count


        //up
        if (newPair.first - value >= 0 && (int)visited[newPair.first - value][newPair.second] -48 == 0)
        {
        q.push(make_pair(newPair.first -value, newPair.second));
        newNeighbors++;
        }
        //down
        if (newPair.first + value < m && (int)visited[newPair.first + value][newPair.second] - 48 == 0)
        {
            q.push(make_pair(newPair.first + value, newPair.second));
            newNeighbors++;
        }
        //left
        if (newPair.second - value >= 0 && (int)visited[newPair.first][newPair.second - value] - 48 == 0)
        {
            q.push(make_pair(newPair.first, newPair.second - value));
            newNeighbors++;
        }
        //right
        if (newPair.second + value < n && (int)visited[newPair.first][newPair.second + value] - 48 == 0)
        {
            q.push(make_pair(newPair.first, newPair.second + value));
            newNeighbors++;
        }

        if (visited[m-1][n-1] == 1)
        {
            found = true;
            break;
        }
        neighbors--;
        if (neighbors == 0)
        {
            level++;
            neighbors = newNeighbors;
            newNeighbors = 0;
        }

    }
    //count steps
    if (found)
    {
        cout << level << endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }



}
