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
#include <map>
#include <sstream>

using namespace std;

int main()
{
    string s; cin >> s;
    string spaces = "";
    string current = "";
    for(int i=0; i<s.size(); i++)
    {
        char c = s[i];

        bool comma = false;
        if (i != s.size()-1 && s[i+1] == ',')
        {
            comma = true;
        }

        if (c == '{')
        {
            cout << spaces << c << endl;
            spaces += "  ";
        }
        else if (c == '}')
        {
            if (current.size() > 0) {
                cout << spaces << current << endl;
                current = "";
            }
            bool su = false;
            if (spaces.size() != 0) {
                su = true;
                spaces = spaces.substr(2);
            }
            if (s[i-1] == '}' && su) spaces += "  ";
            if (comma) {

                cout << spaces << c << ','<< endl;
                i++;
            } else {
                cout << spaces << c  << endl;
                if (spaces.size() != 0) spaces = spaces.substr(2);
            }
        } else {
            current += c;
            if (comma) {
                cout << spaces << current << ',' << endl;
                current = "";
                i++;
            }
        }

    }
}

/*
{a,b,{c,{d},{f}},e,{}}

{{{{}}}}

*/
