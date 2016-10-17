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
#include <map>
#include <sstream>

using namespace std;

int main()
{
    int start; cin >> start;
    int ex = 210;
    int p; cin >> p;
    int ans;
    for(int i=0; i<p; i++)
    {
        int t; cin >> t;
        char c; cin >> c;
        ex -= t;
        if (ex <= 0) {
            break;
        }
        if (c == 'T') {
            start++;
            if (start > 8) {
                start %= 8;
            }
        }


    }
    cout << start << endl;
}
