#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <queue>
#include <unordered_map>
#include <iomanip>

using namespace std;
typedef vector<int, int> vii;
typedef vector<int> vi;
typedef pair<int, int> p;
typedef map<int, int> mii;
typedef map<string, int> msi;
typedef unordered_map<int, int> umii;
typedef unordered_map<string, int> umsi;

int main()
{
    string a; cin >> a;
    unordered_map<char, long long> seat;
    seat['f'] = 1; seat['e'] = 2; seat['d'] = 3; seat['a'] = 4; seat['b'] = 5; seat['c'] = 6;
    char seats = a[a.size()-1];
    a.pop_back();
    long long n = atol(a.c_str());
    long double four = 4.00;
    long long temp = ceil(n/four) - 1;
    long long ans = (temp * 4) + seat[seats] + (2*temp * 6);
    if (n % 4 == 2 || n % 4 == 0) {
        ans += 7;
    }
    cout << ans << endl;
}
