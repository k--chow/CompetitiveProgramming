
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
#include <queue>
#include <stack>
using namespace std;

int main()
{
    int cases;
    for(int i=0; i<cases; i++)
    {
        int s;
        cin >> s;
        vector<int> scores;
        for(int j=0; j<s; j++)
        {
            int score;
            cin >> score;
            scores.push_back(score);
        }
        sort(scores.begin(), scores.end());
        int b = 100 - scores[scores.size()-1];
        cout << b << endl;
    }
}
