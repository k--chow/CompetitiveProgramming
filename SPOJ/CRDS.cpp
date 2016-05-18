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

int main()
{
    int cases;
    cin >> cases;
    for(int i=0; i<cases; i++)
    {
        long long n;
        cin >> n;
        long long ans = (((n)*(n-1))/2) + (n*(n+1));
        cout << ans % 1000007<< endl;

    }
}
