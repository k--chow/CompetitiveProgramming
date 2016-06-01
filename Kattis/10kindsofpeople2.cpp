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

void dfs(vector< vector<char> >& graph, bool & found, char start, int a1, int a2, int b1, int b2, vector< vector<bool> >&visited, int r, int c)
{
    if (a1 == b1 && a2 == b2)
    {
        found = true;
        //cout << "YAY" << endl;

    }
    else
    {
    //cout << "HERE: " << a1 << " " << a2 << endl;
    //up
    if (a1 != 0)

    {
        if (!visited[a1-1][a2] && graph[a1-1][a2] == start)//not previous
        {
            //dfs and set previous
            visited[a1-1][a2] = true;
            dfs(graph, found, start, a1-1, a2, b1, b2, visited, r, c);

        }
    }
    //down
    if (a1 != r-1 )
    {
        if (!visited[a1+1][a2] && graph[a1+1][a2] == start)
        {
            visited[a1+1][a2] = true;
            dfs(graph, found, start, a1+1, a2, b1, b2, visited, r, c);
        }
    }

    //left
    if (a2 != 0)
    {
        if (!visited[a1][a2-1] && graph[a1][a2-1] == start)
        {
            visited[a1][a2-1] = true;
            dfs(graph, found, start, a1, a2-1, b1, b2, visited, r, c);
        }
    }
    //right
    if (a2 != c-1 )
    {
        if (graph[a1][a2+1])
        {
            if (graph[a1][a2+1] == start)
            {
            visited[a1][a2+1] = true;
            dfs(graph, found, start, a1, a2+1, b1, b2, visited, r, c);
            }
            else
            {
                //cout << "not start" << endl;
            }
        }
        else
        {
            //cout << "is previous" << endl;
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
    vector< vector<bool> > visited2(r);
        for(int a=0; a<r; a++)
        {
            for(int b=0; b<c; b++)
            {
                visited2[a].push_back(false);
            }
        }
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
        vector< vector<bool> > visited = visited2;

        dfs(graph, found, start, a1-1, a2-1, b1-1, b2-1, visited, r, c);

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
        }
        //cout << start << endl;
    }
}
