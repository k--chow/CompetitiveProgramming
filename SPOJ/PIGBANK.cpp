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

typedef pair<pair<int, int>, int> p;
typedef vector<int> vi;
typedef vector<vi> vii;

#define INF 99999999

int main()
{
    int tCases;
    cin >> tCases;
    for(int a=0; a<tCases; a++)
    {
        int E, F;
        cin >> E >> F;
        int arraySize = F-E+1;

        //get the coins
        int coinNumber;
        cin >> coinNumber;
        vector<int> values;
        vector<int> costs;
        values.push_back(0);
        costs.push_back(0);
        for(int i=0; i<coinNumber; i++)
        {
            int v, c;
            cin >> v >> c;
            values.push_back(v);
            costs.push_back(c);
        }
        //cout << "arraySize: " << arraySize << endl;
        vector<long long> DP (arraySize, INF);
        DP[0] = 0;
        //do DP calculations
        for(int i=1; i<values.size(); i++)
        {
            for(int j=1; j<arraySize; j++)
            {
                if (costs[i] <= j)
                {
                    DP[j] = min(DP[j], DP[j-costs[i]] + values[i]);
                }/*
                else
                {
                    DP[j] = DP[j-1];
                }*/
                cout << DP[j] << " ";

            }
            cout << endl;

        }

        if (DP[arraySize-1] != INF)
        {
            cout << "The minimum amount of money in the piggy-bank is " << DP[arraySize-1] << "." << endl;
        }
        else
        {
            cout << "This is impossible." << endl;
        }


    }
}
