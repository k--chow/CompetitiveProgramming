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
int r, c;

int solve(vector< vector<int> > matrix, vector< vector<int> > & DP)
{
    //loop through the top of i's
    //loop inside the j's
    for(int i=1; i<r; i++) //start from 1 to r+1 because of padding
    {
        for(int j=0; j<c; j++)
        {
            //special cases j = 0 or j = c-1
            if (j == 0 || j == c-1)
            {
                if (j==0)
                {
                    DP[i][j] = DP[i][j] + max(DP[i-1][j], DP[i-1][j+1]);
                }
                else
                {
                    DP[i][j] = DP[i][j] + max(DP[i-1][j-1], DP[i-1][j]);
                }
            }
            else
            {
                DP[i][j] = DP[i][j] + max(max(DP[i-1][j-1], DP[i-1][j]), DP[i-1][j+1]);
            }

        }
    }
    int m = 0;

    for(int j=0; j<c; j++)
    {
        m = max(m, DP[r-1][j]);
    }
    return m;

}

int main()
{
    int cases;
    cin >> cases;
    for(int i=0; i<cases; i++)
    {
        cin >> r >> c;
        vector< vector<int> > matrix(r);
        vector< vector<int> > DP(r);

        /*
        //for padding 0's on top
        for(int j=0; j<c; j++)
        {
            //matrix[0].push_back(0);
            //DP[0].push_back(0);
        }*/

        for(int j=0; j<r; j++)
        {
            for(int k=0; k<c; k++)
            {
                int a;
                cin >> a;
                matrix[j].push_back(a);
                DP[j].push_back(a);
                //cout << matrix[j][k] << " ";
            }
        }


        //do actions here
        cout << solve(matrix, DP) << endl;


    }


}
