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

void dijkstras(vector< vector<int> > & matrix, vector<int> & visited, vector<int> & dist, int start, int end)
{
    visited[start] = 1; //set node as visited
    //traverse through the bih
    for(int i=0; i<matrix[start].size(); i++)
    {
        if (visited[i] == 0 && matrix[start][i] != -1)// unvisited and matrix not -1
        {
            int newDistance = dist[start] + matrix[start][i];
            if (newDistance < dist[i])
            {
                dist[i] = newDistance;
            }
        }
    }

    //terminating conditions
    if (visited[end] == 1)
    {
        return;
    }
    else
    {
        int node;
        int smallest = 100000;
        //get smallest unvisited
        for(int i=0; i<dist.size(); i++)
        {
            if (visited[i] == 0 && dist[i] < smallest)//unvisited and smaller than smallest
            {
                smallest = dist[i];
                node = i;
            }
        }

        if (smallest == 100000)
        {
            return;
        }
        else
        {
            dijkstras(matrix,  visited, dist, node, end);
        }
    }

}

int main()
{
    int cases;
    cin >> cases;

    for(int i=0; i<cases;i++)
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
        //edges
        for(int j=0; j<edges; j++)
        {
            //not bidirectional
            int a,b,c;
            cin >> a >> b >> c;
            matrix[a-1][b-1] = c;
        }
        int start,end;
        cin >> start >> end;
        //implementation detail
        dist[start-1] = 0;
        //now d
        dijkstras(matrix, visited, dist, start-1, end-1);
        //print out dist or NO
        if (dist[end-1] == 100000)
        {
            cout << "NO" << endl;
        }
        else
        {
        cout << dist[end-1] << endl;
        }
    }
}
