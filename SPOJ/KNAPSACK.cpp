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

int main()
{

    int s, N;
    cin >> s >> N;
    vector<int> values;
    vector<int> weights;
    vii DP(s+1);

    for (int i=0; i<N; i++)
    {
        int v, w;
        cin >> v >> w;
        values.push_back(v);
        weights.push_back(w);
    }

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<s+1; j++)
        {
            DP[i][j] = 0;
        }
    }


    for(int i=1; i<N; i++)
    {
        for(int j=1; j<s+1; j++)
        {
            if (weights[i] <= j)
            {
                DP[i-1][j] = max(DP[i-1][j], DP[i-1][j-weights[i]] + values[i]);
            }
            //cout << DP[j] << " ";

        }
        //cout << endl;
    }
    /*
    for(int j=0; j<s+1; j++)
    {
        cout << DP[j] << " ";
    }*/
    cout << DP[N-1][s-1] << endl;

}




