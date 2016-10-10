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
using namespace std;
int s;
vector<int> arr;
int ans = 2147483647;
void backtrack(int i, bool g, int currentSum)
{
    //cout << "called " << i  << endl;
    //check if all reached
    if (i == ((1 << (s))-1)) {
        //cout << "ayy" << endl;
        if (currentSum < ans) {
            ans = currentSum;
        }
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
    for(int i=0; i<s; i++)
    {
        int p; cin >> p;
        arr.push_back(p);
    }
    backtrack(0, false, 0);
    cout << ans << endl;
}
