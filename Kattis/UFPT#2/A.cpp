#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unordered_map>
#include <map>
using namespace std;
int s;
vector<int> arr;
map<pair <int, bool>, int> dp;
int f;
void backtrack(int i, bool g, int currentSum)
{

    //cout << "called " << i  << endl;
    //check if all reached
    if (i == f)
    {
        if (dp.count(make_pair(f, g)))
        {
            int value = dp[make_pair(f, g)];
            dp[make_pair(f, g)] = min(value, currentSum);
        } else {
            dp[make_pair(f, g)] = currentSum;
        }
        return;
    }
    if (dp.count(make_pair(i, g)) && currentSum > dp[make_pair(i, g)]) {
        return;
    } else {
        dp[make_pair(i, g)] = currentSum;
    }
    //if gate
    if (g) {
        //pick one to go back

        int mini = 2147483647;
        int index = 0;
        for(int j=0; j<s; j++)
        {
            if (((i) & (1 << j)))
            {
                if (arr[j] < mini) {
                    mini = arr[j];
                    index = j;
                }

            }
        }
        backtrack(i - (1 << index), false, currentSum + mini);

    }
    //if not gate
    else {
        //pick two to go with
        for(int j=0; j<s; j++)
        {
            if (((i) & (1 << j)) == 0) {
                for(int k = j+1; k<s; k++)
                {
                    if (((i) & (1 << k)) == 0) {
                        backtrack(i + (1 << j) + (1 << k), true, currentSum + max(arr[j], arr[k]));
                    }
                }
            }
        }
    }
}

int main()
{
    cin >> s;
    f = (1 << (s))-1;
    for(int i=0; i<s; i++)
    {
        int p; cin >> p;
        arr.push_back(p);
    }
    clock_t t1, t2;
    t1 = clock();
    backtrack(0, false, 0);
    /*
    for(int i = 0; i <=f; i++)
    {
        cout << dp[make_pair(i, 1)] <<endl;
    }*/
    cout << dp[make_pair(f, 1)] <<endl;
    t2 = clock();
    cout << ((float)t2 - (float)t1)/CLOCKS_PER_SEC << endl;
}
