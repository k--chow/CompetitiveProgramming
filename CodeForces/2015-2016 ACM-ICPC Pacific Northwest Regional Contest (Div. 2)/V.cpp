#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> p;
typedef pair< vector<int>, int> p2;
typedef pair< pair<int, int>, int> p3;

int main()
{
    int gears;
    cin >> gears;
    vi gearss;
    for(int i=0; i<gears; i++)
    {
        int x, y, r;
        cin >> x >> y >> r;
        vector<int> t;
        t.push_back(x);
        t.push_back(y);
        p3 b = make_pair(make_pair(x, y), r);
        cout << b.first.first << endl;
    }

}
