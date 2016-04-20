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
    while (1)
    {
        //cout << endl;
        vector<long long> DP;
        long long ans = -1;
        DP.push_back(1);
        string input;
        cin >> input;
        if (input == "0")
        {
            break;
        }
        input = "1" + input;
        //traverse the input
        for(int i=1; i<input.length(); i++)
        {
            int a = input[i] - '0';
            //cout << "a: " << a << endl;
            //if not zero, DP[i] = DP[i-1]
            if (a != 0)
            {
                DP.push_back(DP[i-1]);
                //cout << "DP: " << DP[i] << endl;
                string b = input.substr(i-1, 2);
            //if this and previous create a pair, DP[i]+=DP[i-2];
            int c = atoi(b.c_str());
            if ((c < 27 && c > 0) && i != 1 && input[i-1] != '0')
            {

                DP[i] += DP[i-2];
            }
            else if (c == 0)
            {
                ans = 0;
                break;
            }
            }
            else
            {
                DP.push_back(DP[i-2]);
            }





            //cout << i << " " << DP[i] << " " << a << endl;

        }
        if (ans == -1)
        {
            ans = DP[input.length()-1];
        }
        cout << ans << endl;

    }




}
