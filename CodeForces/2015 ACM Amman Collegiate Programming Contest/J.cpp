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
#include <map>
#include <unordered_map>
using namespace std;

typedef pair<int, int> p;

bool pairCompare(const p &first, const p &second)
{
    return first.first < second.first;
}

int main()
{
    int cases;
    cin >> cases;

    for(int i=0; i<cases; i++)
    {
        unordered_map<int, int> ages;
        unordered_map<int, int> candies;
        vector<int> agess;
        vector<int> candiess;
        int a, b;
        cin >> a >> b;
        for(int j=0; j<a; j++)
        {
            int a1;
            cin >> a1;
            unordered_map<int, int>::const_iterator it = ages.find(a1);
            //find in hashmap
            if(it == ages.end())//not found
            {
                agess.push_back(a1);
                ages[a1] = 1;
            }
            else
            {
                ages[a1]++;
            }
        }

        for (int j=0; j<b; j++)
        {
            int b1;
            cin >> b1;
            unordered_map<int, int>::const_iterator it = candies.find(b1);
            //find in hashmap
            if(it == ages.end())//not found
            {
                candiess.push_back(b1);
                candies[b1] = 1;
            }
            else
            {
                candies[b1]++;
            }
        }

        sort(agess.begin(), agess.end());
        sort(candiess.begin(), candiess.end());



    //cout << candies[2] << endl;
    //try to map ages to candies
    bool yes = true;
    int current = 0;
    for (int i=0; i<agess.size(); i++) //traver through ages in sorted ordered
    {
        //int mapA = agess[i];
        //map each age to candies
        while (1)
        {
            if (current == candiess.size()) {
                yes = false;
                break;
            }


            if (candies[candiess[current]] >= ages[agess[i]])
            {
                //cout << candiess[current] << " to " << agess[i] << endl;
                current++;
                break;
            }
            current++;


        }


        if (!yes) break;
    }

    if (yes) cout << "YES" << endl;
    if (!yes) cout << "NO" << endl;
    }


}
