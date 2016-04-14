#include <algorithm>
#include <vector>
#include <tuple>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
using namespace std;

class Interval {
public:
    int start;
    int fun;
    int ending;
    //constructor
    Interval(int start, int fun, int ending) : start(start), fun(fun), ending(start+ending) {}
    //basically compareTo method
    bool operator < (const Interval& interval) const
    {
        if (ending == interval.ending)
        {
            return (start < interval.start);
        }
        else
        {
            return (ending < interval.ending);
        }

    }
};

int main() {
    int cases;
    cin >> cases;
    vector<Interval> v;
    for(int i=0; i<cases; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back(Interval(a, b, c));
    }


    sort(v.begin(), v.end());
    //cout << v[3].ending << endl;
    vector<int> dp(v.size());

    for(int i=0; i<v.size(); i++)
    {
        //speed this up now!
        int largest = 0;
        for(int j=0; j<i; j++)
        {
            if (dp[j] > largest && v[j].ending <= v[i].start)
            {
                largest = dp[j];
            }
        }
        dp[i] = v[i].fun + largest;
    }
    int largest = 0;

    for(int i=0; i<v.size(); i++)
    {
        if (dp[i] > largest) largest = dp[i];
    }
    cout << largest << endl;
}
