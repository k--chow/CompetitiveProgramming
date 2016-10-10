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
/*
int main()
{
    int cases; cin >> cases;
    const double majority = 0.50000;
    for(int i=0; i<cases; i++)
    {
        int n; cin >> n;
        double total = 0;
        double maximum;
        bool noWinner = true;
        int index = 1;
        for(int j=0; j<n; j++)
        {
            int c; cin >> c;
            if (j == 0) {
                maximum = c;
            } else {
                if (c > maximum)
                {
                    noWinner = false;
                    maximum = c;
                    index = j+1;
                } else if (c < maximum) {
                    noWinner = false;
                }
            }
            total += c;
        }
        if (noWinner) {
            cout << "no winner" << endl;
        } else {
            //cout << (double)(maximum/total) << endl;
            if (((double)maximum/total) > majority) {
                cout << "majority winner " << index << endl;
            } else {
                cout << "minority winner " << index << endl;
            }
        }
    }
}*/

int main()
{
    int cases; cin >> cases;
    for(int i=0; i<cases; i++)
    {
        int candidates; cin >> candidates;
        vector<int> candidate;
        bool noWinner = true;
        for(int j=0; j<candidates; j++)
        {
            int c; cin >> c;
            candidate.push_back(c);
        }
        double maximum = candidate[0];
        double total = candidate[0];
        int index = 1;
        for(int j=1; j<candidates; j++)
        {
            if (candidate[j] != maximum) {
                noWinner = false;
            }
            if (candidate[j] > maximum) {
                index = j + 1;
                maximum = candidate[j];
            }
            total += candidate[j];
        }
        for(int j=1; j<candidates; j++)
        {
            if (j != index - 1) {
                if (candidate[j] == maximum) {
                    noWinner = true;
                }
            }
        }
        if (noWinner) {
            cout << "no winner" << endl;
        } else {
            bool majority = ((maximum/total) > 0.5);
            if (majority) {
                cout << "majority winner " << index << endl;
            } else {
                cout << "minority winner " << index << endl;
            }
        }
    }
}

/*
5
3
10
21
10
3
20
10
10
3
10
10
10
4
15
15
15
45
3
100
100
4

*/
