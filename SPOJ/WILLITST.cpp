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
    long double n;
    cin >> n;
    if (fmod(log2l(n), 1) == 0 || n == 0) {
        cout << "TAK" <<endl;
    }
    else
    {
        cout << "NIE" <<endl;
    }
}
