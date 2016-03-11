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

void d(vector< vector<int> > & matrix, vector<int> & visited, vector<int> & dist, int start, int end)
{
    visited[start] = 1;
    //traverse through each neighbor and update values
    for(int i=0; i<matrix[start].size(); i++)
    {
        if (visited[i] == 0 && matrix[start][i] != -1)//edge exists and unvisited
        {
            if (dist[start] + matrix[start][i] < dist[i])
            {
                dist[i] = dist[start] + matrix[start][i];
            }
        }
    }

    //if visited[end] is 1 return
    if (visited[end] == 1)
    {
        return;
    }
    //else find smallest dist thats unvisited
    else
    {
        int node, distance = 100000;
        //if 100,000 - return because can't reach, else d again
        for(int i=0; i<dist.size(); i++)
        {
            if (visited[i] == 0 && dist[i] < distance)
            {
                distance = dist[i];
                node = i;
            }
        }

        if (distance == 100000)
        {
            return;
        }
        else
        {
            d(matrix, visited, dist, node, end);
        }
    }



}

int main()
{
    int cases;
    cin >> cases;
    for(int i=0; i<cases; i++) //cases
    {
        int nodes, edges;
        cin >> nodes >> edges;
        vector<int> visited(nodes, 0);
        vector<int> dist(nodes, 100000);
        vector< vector<int> > matrix(nodes);
        //set matrix to -1

        for(int k=0; k<nodes; k++)
        {
            for(int k2 = 0; k2<nodes; k2++)
            {
                matrix[k].push_back(-1);
            }
        }
        //set the graph in

        for(int j=0; j<edges; j++)
        {
            int a,b,c;
            cin >> a >> b >> c;
            if (matrix[a-1][b-1] != -1)
            {
                if (c < matrix[a-1][b-1])
                {
                    matrix[a-1][b-1] = c;
                    matrix[b-1][a-1] = c;
                }
            }
            else
            {
            matrix[a-1][b-1] = c;
            matrix[b-1][a-1] = c;
            }
        }
        int start;
        cin >> start;
        //set dist to 0
        dist[start-1] = 0;
        //enter d with correct start and end
        d(matrix, visited, dist, start-1, nodes-1);
        for(int j=0; j<dist.size(); j++)
        {
            if (j != start-1)
            {
                if (dist[j] == 100000)
                {
                    cout << -1 << " ";
                }
                else
                {
                cout << dist[j] << " ";
                }
            }
        }
        cout << endl;


    }
}
