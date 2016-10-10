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

int totalSum(int i, vector<int> & arr, int s)
{
    //return sum
    int sum = 0;
    for(int j=0; j<s; j++)
    {
        if ((i) & (1 << j))
        {
            sum += arr[j];
        }
    }
    return sum;
}

void recoverSolution(int i, vector<int> & arr, int s)
{
    for(int j=0; j<s; j++)
    {
        if ((i) & (1 << j))
        {
            cout << arr[j] << " ";
        }
    }
    cout << endl;
}

int main()
{
    int cases; cin >> cases;
    for(int i=0; i<cases; i++)
    {
        vector<int> arr;
        unordered_map<int, int> sums;
        int s; cin >> s;
        for(int j=0; j<s; j++)
        {
            int p; cin >> p;
            arr.push_back(p);
        }
        //bit stuff
        int b = 1;
        int c;
        bool ans = false;
        //cout << ((1) & (1 << 1)) << endl;
        for(;b <= (1 << s); b++)
        {
            //get sum, store sum to int
            int sum = totalSum(b, arr, s);
            //cout << sum << endl;
            //if sum is in map, break
            if (sums.count(sum)) {
                c = sums[sum];
                ans = true;
                break;
            } else {
                sums[sum] = b;
            }
            //otherwise store it
        }
        if (!ans) {
            cout << "Impossible" << endl;
        } else {
            //print out answer
            cout << "Case #" << i+1 << ":" << endl;
            recoverSolution(c, arr, s);
            recoverSolution(b, arr, s);
        }
    }
}
/*
3
20 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
20 122 266 859 1233 1657 1771 2328 2490 2665 2894 3117 4210 4454 4943 5690 6170 7048 7125 9512 9600
4 1 3 10 19
*/
