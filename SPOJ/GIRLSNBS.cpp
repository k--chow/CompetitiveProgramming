#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>
#include <iomanip>
using namespace std;

int main()
{
    while (1)
    {
        int G, B;
        cin >> G >> B;
        if (G == -1 && B == -1) break;
        double larger, smaller;
        if (G > B)
        {
            larger = G;
            smaller = B;
        }
        else
        {
            larger = B;
            smaller = G;
        }
        int ans;
        double preAns = larger/(smaller+1);
        if (fmod(preAns, 1) != 0)
        {
            preAns = ceil(larger/(smaller+1));
        }
        else
        {
            preAns = larger/(smaller+1);
        }
        cout << preAns << endl;
    }
}
