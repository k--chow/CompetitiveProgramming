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

int solve(vector< vector<int> > & DP, int weight, int fun, int i, int j, int & currentWeight, bool & yes) // weight of item, fun of item, current j weight
{
    if (weight > j)
    {
        return DP[i-1][j];
    }
    else
    {
        if (DP[i-1][j-weight] + fun > DP[i-1][j] && yes == 0)
        {
            yes = true;
            currentWeight+=weight;
            cout << yes << " " << currentWeight << " += " << weight << " " << DP[i-1][j-weight] + fun << endl;;
        }

        return max(DP[i-1][j], DP[i-1][j-weight] + fun);
    }
}

int main()
{
    while(1)
    {
        int total, items;
        cin >> total >> items;
        if (total == 0 && items == 0)
        {
            break;
        }
        vector<int> weights;
        vector<int> fun;
        for(int i=0; i<items; i++)
        {
            int a, b;
            cin >> a >>b;
            weights.push_back(a);
            fun.push_back(b);
            //cout << weights[i] << " " << fun[i] << endl;

        }

        vector< vector<int> > DP(items);
        for(int i=0; i<items; i++)
        {
            for(int j=0; j<total; j++)
            {
                DP[i].push_back(0);
            }
        }
        int currentWeight = 0;
        bool yes = false;

        for(int i=1; i<items; i++)
        {yes = false;
            for(int j=0; j<total; j++)
            {

                DP[i][j] = solve(DP, weights[i], fun[i], i, j, currentWeight, yes);
                //cout << DP[i][j] << " ";
            }
            //cout << endl;
        }

        cout << currentWeight << " " << DP[items-1][total-1] <<  endl;



    }
}
