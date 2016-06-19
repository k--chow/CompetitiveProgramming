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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long length;
    while (cin >> length )
    {

    //precompute KMP
    //base case is 0, if equal increment TO SELF, not to the other.
    string pattern;
    //string str;
    //cin >> pattern >> str;
    long long LPS[pattern.length()];
    LPS[0] = 0;
    int i=1, len = 0;
    while (i < pattern.length())
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            LPS[i] = len;
            i++;
        }
        else //mismatch
        {
            if (len == 0)//base case, why?
            {

                LPS[i] = 0;
                i++;
            }
            else
            {
                len = LPS[len-1];
                //need i++? NO
            }
        }
    }
    /*
    for(i=0; i<pattern.length(); i++)
    {
        cout << LPS[i] << " ";
    }*/

    //now traverse , if match keep going, if mismatch go to new index?
    int j=0;//i for traversing, j for matching length
    i=0;
    char s;
    while (scanf("%c", &s) != EOF)
    {
        if (s=='\n') break;
        //cout << "ho" <<endl;
        if (s == pattern[j])//match
        {
            i++;
            j++;
            //cout << "ho" << endl;
            if (j == pattern.length())
            {
                cout << i-j << endl;

                j = LPS[j-1];
            }
        }
        else //no match
        {
            //some previous matches
            if (j != 0)
            {
                j = LPS[j-1];
            }
            i++;


        }


    }

    cout << endl;

    }


}
