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
    for(int i=0; i<cases; i++)
    {
        long long c;
        cin >> c;
        long long a = ((c-1)*500) + 192;
        cout << a << endl;
    }
}
