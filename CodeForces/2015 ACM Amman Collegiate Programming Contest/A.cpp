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

typedef pair<int, int> p;

int main()
{

    int cases;
    cin >> cases;
    for(int i=0; i<cases; i++)
    {
        int teams;
        cin >> teams;
        vector<p> points;
        vector<string> names;
        for(int j=0; j<teams; j++)
        {
            string team;
            int pr, pe;
            cin >> team >> pr >> pe;
            names.push_back(team);
            points.push_back(make_pair(pr, pe));
        }
        int most = -1;
        int index = -1;
        for(int j=0; j<teams; j++)
        {

            if (points[j].first == most && points[j].second < points[index].second)
            {
                index = j;
            }

            if (points[j].first > most)
            {
                index = j;
                most = points[j].first;
            }



        }
        cout << most << " " << index << endl;

    }
}
