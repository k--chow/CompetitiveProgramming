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


//write RMQ function to find smallest level in between indexes

//write LCA function to return euler[RMQ(first_occurence[i], first_occurence[j], level)]

void DFS (vector<int> & euler, vector<int> & level, vector< vector<int> > graph,  int current, int previous)
{
    //get all the neighbors
    for(int i=0; i<graph[current].size(); i++)
    {
        //make sure its not parent(previous)
        if (graph[current][i] != previous)
        {
            euler.push_back(graph[current][i]);
            DFS(euler, level, graph, graph[current][i], current);
            euler.push_back(current); //come back, but not if its the end
        }

    }
    //go to the first one

}

int main()
{
    int n;
    cin >> n;
    vector< vector<int> > graph(n); //safe the graph
    for(int i = 0; i<n; i++)//store the graph
    {
        int children;
        cin >> children;
        for(int j=0; j<children; j++)
        {
            int child;
            cin >> child;
            graph[i].push_back(child); //to
            graph[child].push_back(i); //from

        }
    }


    vector<int> euler(2*n + 1, 0); //save path of DFS
    vector<int> level(2*n + 1, 0); //save level of path of DFS

    //run DFS on graph and save euler and level
    //visited array not needed
    DFS(euler, level, graph, 0, 0);
    for(int i=0; i<euler.size(); i++)
    {
        cout << euler[i] << endl;
    }



    //precompute first_occurence
    vector<int> first_occurence(n, 0); //save first occurence of nodes


}
