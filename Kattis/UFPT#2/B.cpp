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

int main()
{
    int cases; cin >> cases;
    for(int i=0; i<cases; i++)
    {
        unordered_map<string, bool> cities;
        int t; cin >> t;
        for(int j=0; j<t; j++)
        {
            string city; cin >> city;
            if (!cities.count(city))
            {
                cities[city] = true;
            }
        }
        cout << cities.size() << endl;
    }
}
