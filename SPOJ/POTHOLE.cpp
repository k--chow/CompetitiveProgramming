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
#include <stack>
using namespace std;


int main() {
    int cases;
    cin >> cases;
    int chambers;
    cin >> chambers;
    int capacity[chambers][chambers];


    for (int i=0; i<chambers;i++)
    {
        for(int j=0; j<chambers; j++)
        {
            capacity[i][j] = 0;
        }

    }
    //set up matrix
    for (int i=0; i<chambers-1;i++)
    {
        int paths;
        cin >> paths;
        for(int j=0; j<paths; j++)
        {
            int neighbor;
            cin >> neighbor;
            capacity[i][neighbor-1] = 100000;
            if (neighbor == chambers)
            {
                capacity[i][chambers-1] = 1;
            }
        }

    }
    //source +1 all 1
    for(int i=0; i<chambers;i++)
    {
        if (capacity[0][i] > 0)
        {
            capacity[0][i] = 1;
        }
    }

    for (int i=0; i<chambers;i++)
    {
        for(int j=0; j<chambers; j++)
        {
            cout << capacity[i][j] << " ";
        }
        cout << endl;

    }



    while (true)
    {

        //bfs find path to residual graph
        stack<int> path; //keeps track of path
        queue<int> q;
        vector<int> pred(chambers, -1);
        vector<int> visited(chambers, 0);
        //implement first neighbors
        visited[0] = 1; //set first to visited
        //store predecessor as self
        pred[0] = -1;
        for(int i=0; i<chambers; i++)
        {
            if (capacity[0][i] > 0) // edge exists
            {
                pred[i] = 0;
                q.push(i);
            }
        }

        while(!q.empty())
        {
            //pop one from queue
            int node = q.front();
            q.pop();
            //set node to visited
            visited[node] = 1;

            //queue up neighbors
            for(int i=0; i<chambers; i++)
            {
                if (capacity[node][i] > 0 && visited[i] != 1) //edge exists and unvisited
                {
                    q.push(i);

                    //store predecessor
                    pred[i] = node;

                }
            }


            //if visited already, break
            if (visited[chambers-1] == 1)
            {
                break;
            }
        }
        /*
        for(int i=0; i<chambers; i++)
        {
                cout << pred[i]+1 <<endl;
        }*/

        //get the path in reverse
        path.push(chambers-1);
        int curr = pred[chambers-1];
        path.push(curr);
        while (curr != 0)
        {
            path.push(pred[curr]);
            curr = pred[curr];
        }
        /*make sure path works
        while (!path.empty())
        {
            cout << path.top() << endl;
            path.pop();
        }*/


        //find min in path
        int m = 100000;
        int s = path.size();

        int from = path.top();
        vector<int> path2;
        path.pop();
        int to;
        path2.push_back(from);
        cout << from << " " << to << endl;
        for(int i=0; i<s-1; i++)
        {
            to = path.top();
            path.pop();
            path2.push_back(to);
            //cout << n+1 << endl;
            if (capacity[from][to] < m) m = capacity[from][to];
            //cout << from << " " << to << " : " << m << endl;
            //make residual graph
            capacity[from][to]-=capacity[from][to];//change this to flow
            capacity[to][from]+=capacity[from][to];
            from = to;
        }

        for(int i=0; i<path2.size(); i++)
        {
            cout << path2[i] << endl;
        }


        //update graph with this min in mind
        from = path2[0];
        for(int i=1; i<path2.size(); i++)
        {
            to = path2[i];
            capacity[from][to]+=m;
            capacity[to][from]-=m;
            from = to;
        }

        for (int i=0; i<chambers;i++)
        {
        for(int j=0; j<chambers; j++)
        {
            cout << capacity[i][j] << " ";
        }
        cout << endl;

        }

        //path not found so exit
        if (visited[chambers-1] == 1)
        {
            break;
        }

    }
}
