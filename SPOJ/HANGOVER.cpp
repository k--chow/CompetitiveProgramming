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

int go(double i)
{
    double t = 0;
    int d = 2; //-1 at end

    while (t<i)
    {
        double c = 1.0/d;
        t+=c;
        d++;
    }
    return d-=2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double i;
    vector<int> ans;
    while (1)
    {
        cin >> i;
        if (i == 0)
        {
            break;
        }
        ans.push_back(go(i));
    }
    for(int j=0; j<ans.size(); j++)
    {
        cout << ans.at(j) << " card(s)" << endl;
    }
}
