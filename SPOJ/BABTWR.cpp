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
    while (1)
    {

        int n;
        cin >> n;
        if (n == 0) break;
        vector<p> towers;

        for(int i=0; i<n; i++)
        {
            int h, w, d;
            cin >> h >> w >> d;
            towers.push_back(make_pair(make_pair(h, w), d));
            towers.push_back(make_pair(make_pair(h, d), w));
            towers.push_back(make_pair(make_pair(w, d), h));
            towers.push_back(make_pair(make_pair(w, h), d));
            towers.push_back(make_pair(make_pair(d, w), h));
            towers.push_back(make_pair(make_pair(d, h), w));
        }



        vector< vector<long long> > DP(towers.size());

        for(int i=0; i<towers.size(); i++)
        {
            for(int j=0; j<towers.size(); j++)
            {
                DP[i].push_back(-1);
            }
        }

        long long largest = -1;
        for(int i=0; i<towers.size(); i++)//Nth item
        {
            for(int j=0; j<towers.size(); j++) //try to take this item
            {
                if (i == 0)
                {
                    DP[i][j] = towers[j].first.first;

                }
                else
                {
                    for(int m = 0; m<towers.size(); m++)
                    {
                        //check if current item towers[j] is smaller than above in width and deph
                        if (towers[j].first.second < towers[m].first.second && towers[j].second < towers[m].second)
                        {
                            DP[i][j] = max(DP[i][j], DP[i-1][m] + towers[j].first.first);

                        }
                    }
                }
                if (DP[i][j] > largest) largest = DP[i][j];
                //cout << DP[i][j] << " ";
            }
            //cout << endl;
        }
        cout << largest << endl;


    }
}
