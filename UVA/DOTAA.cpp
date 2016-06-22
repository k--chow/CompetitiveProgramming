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
    //just have n > towers
    int cases;
    cin >> cases;
    for(int i=0; i<cases; i++)
    {
        int h, t, d, t2=0;
        cin >> h >> t >> d;
        for(int j=0; j<h; j++)
        {
            int t3;
            cin >> t3;
            while ( (t3-=d) > 0)
            {
                //cout << t3 << endl;
                t2++;
            }
        }
        if (t2 >= t)
        {
            cout << "YES" << endl;
            //cout << t2 << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        //cout << t2 << endl;
    }
}
