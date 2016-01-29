#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <unordered_map>
using namespace std;

//partial memoization
std::unordered_map<int, long long> b;

long long int go(int f)
{
    if (f == 0)
    {
        return 0;
    }
    else if (b.count(f) == 1)
    {
        return b[f];
    }
    else if (f/2 + f/3 + f/4 <= f)
    {
        b[f] = f;
        return f;
    }
    else
    {
        int d = go(f/2) + go(f/3) + go(f/4);
        return d;
    }
}
int main()
{
    long long int a;

    vector<long long int> ans;
    scanf("%lld",&a);


        ans.push_back(go(a));







    for(int i=0; i<ans.size(); i++)
    {
        cout << ans.at(i) << endl;
    }

}
