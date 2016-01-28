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
    cin >> cases;
    vector<long long> ans;
    for(int i=0; i<cases; i++)
    {
        long long c;
        cin >> c;
        long long a = ((c-1)*250) + 192;
        ans.push_back(a);
    }

    for(int i=0; i<ans.size(); i++)
    {
        cout << ans.at(i) << endl;
    }
}
