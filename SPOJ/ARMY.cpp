#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <cstring>
#include <queue>
using namespace std;

int main()
{
    //sort first
    //while loop
    //index i and j
    //if i reaches end, j wins
    //if j reaches end, i wins
    //if G[i] == MG[j] j++
    //if G[i] < MG[j] i++
    //if G[i] > MG[j] j++
    int cases;
    cin >> cases;
    for(int c=0; c<cases; c++)
    {
        int nG, nMG;
        cin >> nG >> nMG;
        vector<int> G, MG;
        for(int d=0; d<nG; d++)
        {
            int e;
            cin >> e;
            G.push_back(e);
        }
        for(int d=0; d<nMG; d++)
        {
            int e;
            cin >> e;
            MG.push_back(e);
        }
        sort(G.begin(), G.end());
        sort(MG.begin(), MG.end());
        int i=0,j=0;
        string ans;
        while(1)
        {
            if (i==nG)
            {
                ans ="MechaGodzilla";
                break;
            }
            else if (j == nMG)
            {
                ans = "Godzilla";
                break;
            }

            if (G[i] == MG[j])
            {
                j++;
            }
            else if (G[i] < MG[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }

        cout << ans << endl;
    }

    //^shitty brute force
}
