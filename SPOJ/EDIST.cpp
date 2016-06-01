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

int main()
{
    int cases;
    cin >> cases;
    for(int a=0; a<cases; a++)
    {
        string x, z;
        //int ans;
        cin >> x >> z;
        x = " " + x;
        z = " " + z;
        //Wagner-Fischer
        vector< vector<int> > WF(x.size());
        for(int i=0; i<x.length(); i++)
        {
            for(int j=0; j<z.length(); j++)
            {
                WF[i].push_back(0);
            }
        }

        for(int i=0; i<x.length(); i++)
        {
            string one = x.substr(1, i);
            //cout << one << endl;
            for(int j=0; j<z.length(); j++)
            {
                //if (i == 0 || j == 0) continue;
                string two = z.substr(1, j);
                //cout << two << endl;
                char one1 = one[one.size()-1];
                char two2 = two[two.size()-1];
                if (i == 0 || j == 0) {
                    WF[i][j] = max(i, j);
                }
                else if (one1 == two2)
                {
                    //if (i == 1 && j == 1) cout << one1 << " " << two2 << endl;
                    WF[i][j] = WF[i-1][j-1];
                }
                else {
                    //if (i == 1 && j == 1) cout << "AY" << endl;
                    WF[i][j] = min(min(WF[i][j-1]+1, WF[i-1][j]+1), WF[i-1][j-1]+1);
                }







            }
        }
        /*
        for(int i=0; i<x.length(); i++)
        {
            for(int j=0; j<z.length(); j++)
            {
                cout << WF[i][j] << " ";
            }
            cout << endl;
        }*/

        int ans = WF[x.length()-1][z.length()-1];
        cout << ans << endl;


    }
}
