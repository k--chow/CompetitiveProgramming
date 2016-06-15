#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <unordered_map>
using namespace std;
int dp[6100][6100];
int ans;

string reverseString(string str)
{
    string str2 = "";
    for(int i=str.length()-1; i>=0; i--)
    {
        str2+=str[i];
    }
    return str2;
}

int main()
{
    int cases;
    cin >> cases;
    for(int i=0; i<cases; i++)
    {
        string str, str2;
        cin >> str;
        //reverse the string
        str2 = reverseString(str);
        //cout << str2 << endl;
        int r=str.length(), c=str.length();
        //preprocessing, set 0's
        for(int a=0; a<r+1; a++){
            for(int b=0; b<c+1; b++)
            {
                //cout << dp[a][b] << " ";
                dp[a][b] = 0;
            }
            //cout << endl;
        }

        //LCS
        for(int a=1; a<r+1; a++)
        {
            char one = str[a-1];
            for(int b=1; b<c+1; b++)
            {
                char two = str2[b-1];
                //if equal, -1-1 add one
                if (one == two)
                {
                    dp[a][b] = dp[a-1][b-1] + 1;
                }
                dp[a][b] = max(max(dp[a-1][b], dp[a][b-1]), dp[a][b]);
                //max (-1, -1, -1-1)
                //cout << dp[a][b] << " ";

            }
            //cout << endl;
        }
        //cout << "hi" << endl;

        //ans = length - LCS
        ans = str.length() - dp[r][c];
        cout << ans << endl;


    }
}
