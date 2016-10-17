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
        int gears; cin >> gears;
        int ans = 1;
        double maximum = 0;
        for(int j=0; j<gears; j++)
        {
            double a, b, c; cin >> a >> b >> c;
            double R = (b/(2*a));
            if ((-a*(pow(R, 2)) + (b*(R)) + c) > maximum) {
                maximum = (-a*(pow(R, 2)) + b*(R) + c);
                ans = j+1;
            }
        }
        cout << ans << endl;
    }
}
