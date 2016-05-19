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
    while (1)
    {
        int n;
        string ans;
        cin >> n;
        if (n == -1) break;
        n-=1;
        if (n % 6 == 0)
        {
            n/=6;
            int i=1;
            while (n > 0)
            {
                n-=i;
                i++;
            }
            if (n == 0) ans="Y";
            if (n != 0) ans="N";
        }
        else
        {
            ans="N";
        }
        cout << ans << endl;


    }
}
