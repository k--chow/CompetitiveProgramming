#include <iostream>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

string removeSpaces(string input)
{
    input.erase(remove(input.begin(), input.end(), ' '), input.end());
    return input;
}

int main()
{

    int N, c =0;
    scanf("%i\n", &N);
    vector<string> shops;
    vector<string>::iterator it;

    string s;
    for(int i=0; i<N; i++)
    {

       getline(cin, s);

        //cin >> s;
        //s = removeSpaces(s);
        s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
        //cout << " " + s;
        it = find(shops.begin(), shops.end(), s);
        if (it == shops.end())
        {
        shops.push_back(s);

        }
        else
        {
            c++;
        }
    }

    printf("%i\n", c);
    return 0;
}


