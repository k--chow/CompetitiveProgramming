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
    vector<int> squares;
    for(int i=1; i<101; i++)
    {
        squares.push_back(i*i);
    }

    int cases;
    cin >> cases;
    for(int i=0; i<cases; i++)
    {
        string a;

        int M;
        cin >> a;
        int l = a.length();
        int j=0;
        //get closest square, append *
        for(; j<100; j++)
        {
            if (l <= squares[j])
            {
                M = squares[j];
                break;
            }
        }
        while (a.length() != M)
        {
            a+='*';
        }
        //cout << a << endl;
        j++;
        vector< vector<char> > rowMajor(j);
        int index = 0;
        for(int q = 0; q <j; q++)
        {
            for(int w=0; w<j; w++)
            {
                rowMajor[q].push_back(a[index]);
                index++;
                //cout << rowMajor[q][w] << " ";
            }
            //cout << endl;
        }

        //don't flip, just straver bottom up and left right
        string ans = "";
        for(int q=0; q<j; q++)
        {
            for(int w = j-1; w>=0; w--)
            {
                if (rowMajor[w][q] != '*')
                {

                ans+=rowMajor[w][q];
                }
            }
        }
        cout << ans << endl;

    }

}
