#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

void dfs(vector< vector<char> >& graph, bool & found, char start, int a1, int a2, int b1, int b2, int r, int c)
{
    //cout << a1 << " " << a2 << " " << start<< endl;
    if (a1 == b1 && a2 == b2)
    {
        found = true;
        return;

    }
    else
    {
    //cout << "HERE: " << a1 << " " << a2 << endl;
    //up
    if (a1 != 0)

    {
        if (graph[a1-1][a2] == start)//not previous
        {
            //dfs and set previous
            graph[a1-1][a2]++;
            dfs(graph, found, start, a1-1, a2, b1, b2, r, c);

        }
    }
    //down
    if (a1 != r-1 )
    {
        if (graph[a1+1][a2] == start)
        {
            graph[a1+1][a2]++;
            dfs(graph, found, start, a1+1, a2, b1, b2, r, c);
        }
    }

    //left
    if (a2 != 0)
    {
        if (graph[a1][a2-1] == start)
        {
            graph[a1][a2-1]++;
            dfs(graph, found, start, a1, a2-1, b1, b2, r, c);
        }
    }
    //right
    if (a2 != c-1 )
    {

            if (graph[a1][a2+1] == start)
            {
            graph[a1][a2+1]++;
            dfs(graph, found, start, a1, a2+1, b1, b2, r, c);
            }


    }
}
}
int main()
{
    //save graph

    //start at given node, dfs set visited, if at given place break, else nah
    int r, c;
    cin >> r >> c;
    vector< vector<char> > graph(r);

    string a;
    for(int i=0; i<r; i++)
    {
        cin >> a;
        for(int j=0; j<c; j++)
        {
            graph[i].push_back(a[j]);
            //cout << graph[i][j] << " ";
        }
        //cout << endl;
    }
    vector< vector<char> > graph2 = graph;
    int cases;
    cin >> cases;
    for(int i=0; i<cases; i++)
    {
        //row then column
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;
        //now dfs the entire graph
        //no need visited, just previous
        char start = graph[a1-1][a2-1];
        bool found = false;


        dfs(graph, found, start, a1-1, a2-1, b1-1, b2-1, r, c);
        /*
        cout << "new" << endl;
        for(int t=0; t<r; t++)
        {

            for(int y=0; y<c; y++)
            {
                //graph[i].push_back(a[j]);
                cout << graph2[t][y] << " ";
            }
            cout << endl;
        }*/
        graph = graph2;

        //if found
        if (found && start == '1')
        {
            cout << "decimal" << endl;
        }
        else if (found && start == '0')
        {
            cout << "binary" << endl;
        }
        else
        {
            cout << "neither" << endl;
            //cout << found << " s " << start << endl;
        }
        //cout << start << endl;
    }
}
