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
        int ans;
        cin >> x >> z;
        ans = x.length();
        if (z.length() > ans) ans = z.length();
        x = " " + x;
        z = " " + z;
        //LCS
        vector< vector<int> > LCS(x.size());
        for(int i=0; i<x.length(); i++)
        {
            for(int j=0; j<z.length(); j++)
            {
                LCS[i].push_back(0);
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
                if (i == 0 || j == 0) continue;

                if (one1 == two2) {
                    LCS[i][j] = LCS[i-1][j-1] +1;
                    //i++;
                    //LCS[i][j] = max(max(LCS[i][j-1], LCS[i-1][j]), LCS[i][j]);
                    //break;
                    //cout << one1 << " equals " << two2 << endl;

                 }


                //max
                LCS[i][j] = max(max(LCS[i][j-1], LCS[i-1][j]), LCS[i][j]);




            }
        }

        for(int i=0; i<x.length(); i++)
        {
            for(int j=0; j<z.length(); j++)
            {
                cout << LCS[i][j] << " ";
            }
            cout << endl;
        }
        ans -= LCS[x.length()-1][z.length()-1];
        cout << ans << endl;


    }
}
