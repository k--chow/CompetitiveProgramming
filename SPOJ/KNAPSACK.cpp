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
    vii DP(N+1);

    values.push_back(0);
    weights.push_back(0);

    for (int i=0; i<N; i++)
    {
        int v, w;
        cin >> v >> w;
        values.push_back(v);
        weights.push_back(w);
    }

    for(int i=0; i<N+1; i++)
    {
        for(int j=0; j<s+1; j++)
        {
            DP[i].push_back(0);
        }
    }


    for(int i=1; i<N+1; i++)
    {
        for(int j=1; j<s+1; j++)
        {
            if (weights[i] <= j)
            {
                DP[i][j] = max(DP[i-1][j], DP[i][j-weights[i]] + values[i]);
            }

            else
            {
                DP[i][j] = DP[i-1][j];
            }
            cout << DP[i][j] << " ";
        }
        cout << endl;

    }

    cout << DP[N][s] << endl;

}




