#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main()
{
    int cases;
    cin >> cases;
    for(int a=0; a<cases; a++)
    {
        int students;
        cin >> students;
            vector<int> top;
            vector<int> realTop;
            vector<int> bot;
            int i, j;

            for(int c=0; c<students; c++)
            {
                cin >> i;
                top.push_back(i);
            }
            realTop.push_back(top[0]);
            //set realTop
            for(int c=1; c<students; c++)
            {
                realTop.push_back(top[c]-top[c-1]);
            }



            for(int c=0; c<students; c++)
            {
                cin >> j;
                bot.push_back(j);
            }



            //sort both realTop and bot
            //sort(realTop.begin(), realTop.end());
            //sort(bot.begin(), bot.end());
            /*
            for(int c =0; c<realTop.size(); c++)
            {
                cout << realTop[c] << " " << bot[c] << endl;
            }
            cout << endl;*/

            //greedy assign
            int ans = 0;
            //cout << bot[students-1] << " " << realTop[students-1] << endl;
            for(int i=0; i<students; i++)
            {
                if (realTop[i] >= bot[i])
                {
                    ans++;
                }
            }

            cout << ans << endl;



    }

    //absolute value add to array and sort

    //add second values and sort

    //pair them greedily, bottom <= top
}
