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
    int n;
    cin >> n;
    if (n % 10 != 0)
    {
        cout << 1 << endl;
        cout << n % 10 << endl;

    }
    if (n % 10 == 0)
    {
        cout << 2 << endl;
    }
}
