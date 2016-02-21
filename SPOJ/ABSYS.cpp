#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <unordered_map>
using namespace std;

int main()
{
    int cases;
    cin >> cases;
    string m = "machula";
    vector<string> ans;
    for(int i=0; i<cases; i++)
    {
        string a, b, c, d, e, answ;
        int x,y,z;
        cin >> a >>b >> c >> d >> e;
        //only care about a c e

        //find the machula
        //if a = e-c
        //if c = e-a
        //if e = a+c
        if (e.find(m) != string::npos)
        {
            //e-c
            x = atoi(a.c_str());
            //cout << z << endl;
            y = atoi(c.c_str());
            //cout << y << endl;
            z = x + y;
        }

        else if (c.find(m) != string::npos)
        {
            x = atoi(a.c_str());
            z = atoi(e.c_str());
            y = z - x;
        }
        else
        {
            y  = atoi(c.c_str());
            z = atoi(e.c_str());
            x = z - y;
        }

        answ = to_string(x) + " + " + to_string(y) + " = " + to_string(z);
        ans.push_back(answ);

    }

    for(int i=0; i <ans.size(); i++)
    {
        cout << ans.at(i) << endl;
    }

    //edge cases -
}
