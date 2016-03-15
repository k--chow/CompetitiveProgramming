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
using namespace std;

void prims(vector< vector< pair<int, int> > > & list, vector<int> & visited, int start, int & total)
{
    //set start is visited
    visited[start] = 1;
    //traverse through list of start and get
    int mini = 1000000;
    int next = -1;
    for(int i=0; i<visited.size(); i++)
    {
        if (visited[i] == 1) //if included in circle
        {
            for(int j=0; j<list[i].size(); j++)
            {
                if (list[i][j].second < mini && visited[list[i][j].first] == 0)
                {
                    mini = list[i][j].second;
                    next = list[i][j].first;
                }
            }
        }

    }



    //if next is still -1, end
    if (next == -1)
    {
        return;
    }
    else
    {

        total+= mini;
        prims(list, visited, next, total);
    }
    //smallest found
    //do prims again

}

int main()
{
    int cases;
    cin >> cases;
    for(int i=0; i<cases;i++)
    {
        int price;
        cin >> price;
        int nodes, edges;
        cin >> nodes >> edges;
        vector<int> visited(nodes, 0);
        vector< vector< pair<int, int> > > list(nodes);
        for(int j=0; j<edges; j++)
        {
            int a,b,c;
            cin >> a >> b >> c;
            list[a-1].push_back(make_pair(b-1, c*price));
            list[b-1].push_back(make_pair(a-1, c*price));
        }
        /*
        for(int q=0; q<list.size(); q++)
        {
            for(int w=0; w<list[q].size(); w++)
            {
                cout << list[q][w].second << endl;
            }
        }*/
        int total = 0;
        //visited[0] = 1;
        prims(list, visited, 0, total);
        cout << total << endl;

    }

}

/*prims
start at 0 - get the smallest edge visit the new node
have a visited array -
go to smallest edge thats unvisited



*/

