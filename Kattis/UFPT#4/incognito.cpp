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
        int attributes; cin >> attributes;
        map<string, int> counter;
        for(int j=0; j<attributes; j++)
        {
            string a, b; cin >> a >> b;
            if (counter.count(b))
            {
                counter[b]++;
            } else {
                counter[b] = 1;
            }
        }
        int ans = 1;
        for(auto& i: counter)
        {
            ans *= (i.second+1);
        }
        cout << ans - 1 << endl;


    }
}
