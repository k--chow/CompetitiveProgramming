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
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int cases;
    cin >> cases;
    for(int i=0; i<cases; i++)
    {
        int n;
        cin >> n;
        string ans = "";
        for(int j=0; j<n; j++)
        {
                ans += arr[j % 26];
        }
        cout << ans << endl;
    }
}
