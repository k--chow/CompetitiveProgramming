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
    vector<string> ans;
    cin >> cases;
    for(int i=0; i<cases; i++)
    {
        int n;
        cin >> n;
        unsigned long long total = 0;
        for(int j=0; j<n; j++)
        {
            unsigned long long int k;
            cin >> k;
            k %= n;
            total+=k;
        }
        if (fmod(total, n) == 0)
        {
            ans.push_back("YES");
        }
        else
        {
            ans.push_back("NO");
        }

    }
    for(int i=0; i<ans.size(); i++)
    {
        cout << ans.at(i) << endl;
    }
}
