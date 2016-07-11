#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <unordered_map>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a = 0;
    for(int i=0; i<n; i++)
    {
        int b;
        cin >> b;
        a = a ^ b;
    }
    cout << a << endl;
}
