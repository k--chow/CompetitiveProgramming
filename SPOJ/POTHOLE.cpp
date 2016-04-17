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
    int flow [chambers][chambers]; //keeps track of actual flow


    for (int i=0; i<chambers;i++)
    {
        for(int j=0; j<chambers; j++)
        {
            capacity[i][j] = 0;
            flow[i][j] = 0;
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
    /*
    for (int i=0; i<chambers;i++)
    {
        for(int j=0; j<chambers; j++)
        {
            cout << capacity[i][j] << " ";
        }
        cout << endl;

    }*/


    int max_flow = 0;
    while (true)
    {

        //bfs find path to residual graph
        stack<int> path; //keeps track of path
        queue<int> q; //queue for path also
        vector<int> pred(chambers, -1);
        vector<int> visited(chambers, 0);
        //implement first neighbors
        visited[0] = 1; //set first to visited
        //store predecessor as self
        pred[0] = -1;
        for(int i=0; i<chambers; i++)
        {
            if ((capacity[0][i] - flow[0][i]) > 0 || flow[i][0] > 0) //edge exists and unvisited
                {
                    if (visited[i] != 1)// go if unvisited
                    {
                        q.push(i);
                        //store predecessor
                        pred[i] = 0;

                    }


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
                if ((capacity[node][i] - flow[node][i]) > 0 || flow[i][node] > 0) //edge exists and unvisited
                {
                    if (visited[i] != 1)
                    {
                        q.push(i);

                    //store predecessor
                    pred[i] = node;

                    }


                }
            }


            //if visited already, break
            if (visited[chambers-1] == 1)
            {
                break;
            }
        }

        //path not found so exit, max flow is completed
        if (visited[chambers-1] == 0)
        {
            break;
        }

        //get the path in reverse, maybe wrong?
        path.push(chambers-1);
        int curr = pred[chambers-1];
        path.push(curr);
        while (curr != 0)
        {
            path.push(pred[curr]);
            curr = pred[curr];
        }
        /*
        while (!path.empty())
        {
            cout << path.top() << endl;
            path.pop();
        }*/


        //find min in path, possibly wrong
        int m = 1000000;
        int s = path.size();

        int from = path.top();
        vector<int> path2;
        path.pop();
        int to;
        path2.push_back(from);
        //first get path
        for(int i=0; i<s-1; i++)
        {
            to = path.top();
            path.pop();
            path2.push_back(to);
            from = to;
        }

        //find min
        for(int i=0; i<path2.size()-1; i++) {
            from = path2[i];
            to = path2[i+1];
            int test_forward = capacity[from][to] - flow[from][to];
            int test_reverse = flow[to][from];
            if (test_forward > 0)
            {
                m = min(m, test_forward);
            }
            else if (test_reverse > 0) {
                 m = min(m, test_reverse);
            }
        }

        for(int i=0; i<path2.size(); i++)
        {
            cout << path2[i] << endl;
        }


        //augment path add min to forward, substract from reverse edges
        //make residual graph
        for(int i=0; i<path2.size()-1; i++) {
            from = path2[i];
            to = path2[i+1];
            int test_forward = capacity[from][to] - flow[from][to];
            int test_reverse = flow[to][from];
            if (test_forward > 0)
            {
                flow[to][from]+= m;
            }
            else if (test_reverse > 0) {
                flow[to][from]-= m;
            }
        }

        //check flow graph
        for (int i=0; i<chambers;i++)
        {
        for(int j=0; j<chambers; j++)
        {
            cout << flow[i][j] << " ";
        }
        cout << endl;

        }



    }
}
