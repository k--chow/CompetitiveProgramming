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
    int a,b ;
    while (cin >> a >> b)
    {
        if (a == 0 && b == 0) break;
        int counter = 0;
        //3 arrays
        vector<int> q, w, e;
        for(int i=0; i<b; i++)
        {
            int q1, q2, q3;
            cin >> q1 >> q2 >> q3;
            q.push_back(q1+1);
            w.push_back(q2+1);//one indexed
            e.push_back(q3);

        }


        //for loop
        //bool valid
        //for again check if not constraint, break
        //if valid counter++
    }
}
