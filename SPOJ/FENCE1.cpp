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

typedef pair<pair<int, int>, int> p;
typedef vector<int> vi;
typedef vector<vi> vii;

#define PI 3.14159265

int main()
{
    while(1)
    {
        int n;
        cin >> n;
        if (n == 0) break;
        double a = (pow(n, 2)/PI)/2.0;
        std::cout << std::fixed << std::setprecision(2) << a << std::endl;
    }
}
