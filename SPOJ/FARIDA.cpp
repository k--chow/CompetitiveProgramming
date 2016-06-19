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
long long dp[10001];

int main()
{
    int cases;
    cin >> cases;
    dp[0] = 0;
    for(int i=0; i<cases; i++)
    {
        int coins;
        cin >> coins;
        for(int j=1; j<=coins; j++)
        {
            int coin;
            cin >> coin;
            dp[j] = coin;
            for(int k=j-2; k >= 0; k--)
            {
                dp[j] = max(dp[j], coin + dp[k]);
            }
        }
        long long ans = 0;

        for(int j=0; j<=coins; j++)
        {
            ans = max(ans, dp[j]);
            //cout << dp[j] << " ";
        }
        cout << "Case " << i+1 << ": " << ans << endl;



    }
}
