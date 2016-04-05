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
using namespace std;
//char is 96 for 1 index

int main()
{
    int c;
    cin >> c;
    string ans = "a";
    if (c <= 25)
    {
        ans+= (char)97+c;
    }
    else
    {
        bool z = true;
        while (1)
        {
            c-=25;

            if (z)
            {
                ans+='z';
                z = false;
            }
            else
            {
                ans+='a';
                z = true;
            }

            if (c <= 0)
            {
                if (c == -25)
                {
                     c*=-1;
                }
                else
                {

                    c+=25;
                }

                    break;
            }




        }
        //have full string
        if ((25 - c) % 2 != 0)
        {
            ans[ans.length()-1] = 'b';
        }
        int secondChar = 'z' - ((25-c)/2);
        //cout << (char)secondChar << endl;
        ans[1] = (char)secondChar;
    }

    cout << ans << endl;
}
