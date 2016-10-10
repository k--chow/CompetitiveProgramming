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
using namespace std;

int main()
{
    int a, b;
    while (1)
    {
    cin >> a >> b;
    if (a == 0 && b == 0) break;
    int c = a/b;
    a -= (b*c);
    cout << c << " " << a << " / " << b << endl;
    }

}
