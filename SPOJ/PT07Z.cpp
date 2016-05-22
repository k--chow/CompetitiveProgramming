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

void modifiedDFS(vector< vector<int> > & list, int & maximum, int n, int & current, vector<int> &visited)
{
    current+=1;
    visited[n] = 1;
    for(int i=0; i<list[n].size(); i++)
    {
        if (visited[list[n][i]] == 0) {
            modifiedDFS(list, maximum, list[n][i], current,  visited);
        }

    }

    if (current > maximum)
    {
        maximum = current;
    }


    current = -1;
    for(int j=0; j<visited.size(); j++) {
        //cout << visited[j] << " ";
        visited[j] = 0;
    }
    cout << endl;
}

int main()
{
    int N;
    cin >> N;
    vector< vector<int> > list(N);
    vector<int> visited(N, 0);
    for(int i=0; i<N-1; i++)
    {
        int a, b;
        cin >> a >> b;
        list[a-1].push_back(b-1);
        list[b-1].push_back(a-1);
    }
    if (N == 1 || N == 0)
    {
        cout << 0 << endl;
    }
    else
    {


    int maximum = -1;
    int current= -1;
    modifiedDFS(list, maximum, 0, current, visited);
    //modifiedDFS(list, maximum, N-1, current, visited);


    cout << maximum << endl;
    }
}
