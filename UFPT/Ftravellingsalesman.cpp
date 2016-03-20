
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
#include <utility>
#include <iomanip> //for precision
#include <queue>
using namespace std;

struct compare
{
    bool operator() (const pair<int, int> & a, const pair<int, int> & b)
    {
        return a.second > b.second;
    }
};

void prims(vector<int> & visited, vector< vector< pair<int, int> > > list, int & total)
{
    visited[0] = 1; //set first to visited
    priority_queue < pair<int, int>, vector< pair<int, int> >, compare> pq;
    //go through all paths of current circle, find smallest edge, add the new circle
    for(int i=0; i<list[0].size(); i++)
    {
        pq.push(list[0][i]);
    }

    //all visited stop
    while (1)
    {
        bool end = true;
        for(int i=0; i<visited.size(); i++)
        {
            if (visited[i] == 0) // any are unvisited keep going
            {
                end = false;
            }
        }

        if (end)
        {
            return;
        }
        //get next node only if unvisited
        int node = pq.top().first;
        int dist = pq.top().second;
        //pop it
        pq.pop();
        //add its paths
        for(int i=0; i<list[node].size(); i++)
        {
            if (visited[list[node][i].first] == 0) // only if unvisited do it!
            {
                pq.push(list[node][i]);
            }
        }
        //add to total
        total+=dist;
        //set the node to visited
        visited[node] = 1;
        //cout << dist << endl;
    }

}

int main()
{
    int cases;
    cin >> cases;
    for(int i=0; i<cases; i++)
    {
        int N, M, price;
        cin >> price >> N >> M;
        vector<int> visited(N, 0);
        vector< vector< pair<int, int> > > list(N);
        for(int j=0; j<M; j++)
        {
            int X, Y, C;
            cin >> X >> Y >> C;
            list[X-1].push_back(make_pair(Y-1, C*price));
            list[Y-1].push_back(make_pair(X-1, C*price));

        }
        int total = 0;
        prims(visited, list, total);
        cout << total << endl;

        //same place error?
    }
}
