#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <unordered_map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cases;
    cin >> cases;
    for(int i=0; i<cases ;i++)
    {
        int case1;
        cin >> case1;
        int total = 0;
        int previous = -1;
        //cin >> previous;
        int cnt = 0;
        for(int j=0; j<case1; j++)
        {
            int now;
            cin >> now;
            if (now == previous){
                cnt++;
            }
            else
            {
                if (cnt>=3)
                {
                    //previous is good
                }
                else
                {
                    total+=cnt;
                }
                cnt = 1;
            }
            previous = now;

            if (j == case1-1)
            {
                if (cnt < 3) total+=cnt;
            }

        }
        //cout << "Total: " << total << endl;
        if (total > (case1-3))
        {
            cout << "No" << endl;
            //cout << total << endl;
        }
        else
        {
            cout << "Yes" << endl;

        }
    }
}
