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
#include <sstream>

using namespace std;

int main()
{
    int cases; cin >> cases;
    for(int i=0; i<cases; i++)
    {
        int c; cin >> c;
        int ans = 0;
        vector<int> arr;
        for(int j=0; j<20; j++)
        {
            int d; cin >> d;
            arr.push_back(d);
        }
        for(int j=0; j<20; j++)
        {
            int e = arr[j];
            for(int k=j+1; k<20; k++)
            {
                if (arr[k] < arr[j])
                {
                    ans++;
                }
            }
        }
        cout << i+1 << " " << ans << endl;
    }
}
