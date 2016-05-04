#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>

using namespace std;

int solve(vector< vector<pair<int, int> > > & DP, int weight, int fun, int i, int j, int & currentWeight) // weight of item, fun of item, current j weight
{
    if (i == 0)
    {

        if (weight <= j)
        {

            currentWeight = weight;
            return fun; //take, but only once
        }
        else
        {
            currentWeight = 0;
            return 0;
        }
    }
    else if (weight > j)
    {
        currentWeight = DP[i-1][j].second;
        return DP[i-1][j].first;
    }
    else
    {
        if (DP[i-1][j-weight].first + fun > DP[i-1][j].first)
        {

            currentWeight = DP[i-1][j-weight].second + weight;
        }
        else if (DP[i-1][j-weight].first + fun == DP[i-1][j].first && DP[i-1][j-weight].second + weight < DP[i-1][j].second) // equal in fun, take lighter weight
        {
            currentWeight = DP[i-1][j-weight].second + weight;
        }
        else
        {
            currentWeight = DP[i-1][j].second;
        }

        return max(DP[i-1][j].first, DP[i-1][j-weight].first + fun);
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

        vector< vector<pair<int, int> > > DP(items);
        for(int i=0; i<items; i++)
        {
            for(int j=0; j<total; j++)
            {
                DP[i].push_back(make_pair(0, 0));
            }
        }


        for(int i=0; i<items; i++)//items
        {
            for(int j=0; j<total; j++)//weight
            {
                int currentWeight = 0;
                DP[i][j].first = solve(DP, weights[i], fun[i], i, j, currentWeight);
                DP[i][j].second = currentWeight;
                cout << DP[i][j].first << "," << DP[i][j].second << " " ;
            }
            cout << endl;
        }

        cout << DP[items-1][total-1].second << " " << DP[items-1][total-1].first << endl;



    }
}
