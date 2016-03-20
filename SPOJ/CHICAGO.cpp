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

//Implement Dijkstra's with adjacency list and priority queue
void dijkstra(vector< vector<pair<int, double> > >  list, vector<int>& visited, vector<double> & dist, int start, int end)
{
    //set visited of start to 1
    visited[start] = 1;
    //traverse through list[start]
    for(int i=0; i<list[start].size(); i++)
    {
        //if neighborunvisited, and less then replace it
        if (visited[list[start][i].first] == 0)
        {
            double newPercentage = (dist[start] * list[start][i].second)/100.0000000;
            //cout << "New Percentage: " << newPercentage << endl;
            //if newPercentage is higher than current, replace it
            if (newPercentage > dist[list[start][i].first]) //list[start][i].first is the neighbor
            {
                dist[list[start][i].first] = newPercentage;
            }
        }
    }

    //ending cases - unvisited is still -1 or end is visited
    //continue case - unvisited found with highest percentage
    if (visited[end] == 1)
    {
        return;
    }
    else
    {
        int node;
        int highestPercent = -1;
        for(int i=0; i<dist.size(); i++)
        {
            if (visited[i] == 0 && dist[i] > highestPercent)//unvisited and larger
            {
                highestPercent = dist[i];
                node = i;
            }
        }

        if (highestPercent == -1)
        {
            return;
        }
        else
        {
            dijkstra(list, visited, dist, node, end);
        }
    }
}

int main()
{

        //cout << setprecision(6) << fixed;
        while (1)
        {
        int nodes, edges;
        cin >> nodes >> edges;
        if (nodes == 0)
        {
            break;
        }
        vector<  vector< pair<int, double> > > list(nodes);
        //initialize visited nodes all to 0, since all unvisited
        vector<int> visited(nodes, 0);
        vector<double> dist(nodes, 0); //set all distances to 0%
        //pair<to this node, percentage of not getting caught>
        for(int i=0; i<edges; i++)
        {
            int a, b;
            double c;
            cin >> a >> b >> c;
            //pair <int, int> edge(b, c);
            list[a-1].push_back(make_pair(b-1, c/100.0));
            list[b-1].push_back(make_pair(a-1, c/100.0));

        }

        /*
        for(int i=0; i<list.size(); i++)
        {
            cout << "Row " << i << " ";
            for(int j=0; j<list[i].size(); j++)
            {
                cout << list[i][j].first << " dist" << list[i][j].second << " ";
            }
            cout << endl;
        }*/


        //implementation detail
        dist[0] = 1.0;
        //dijkstra 1 to n
        dijkstra(list, visited, dist, 0, nodes-1);

         //cout << dist[nodes-1] << " percent" << endl;
         printf("%.6f percent\n", dist[nodes-1]*100);

        }



}
