#include <iostream>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{
    vector<char> input;
    char c;
    string s;
    cin >> s;
    string a;

    char previous;
    for (char& c:s)
    {
        //input.push(c);

        if (input.empty())
        {
            previous = c;
            input.push_back(c);
        }
        else
        {
            char next = c;
            if (next == previous)
            {
                input.pop_back();

                if (!input.empty())
                {
                    previous = input.back();
                }

            }
            else
            {
                input.push_back(c);
                previous = c;
            }
        }
    }

    for (int i=0; i<input.size(); i++)
    {
        a+=input.at(i);
    }
    cout << a;
    return 0;

}
