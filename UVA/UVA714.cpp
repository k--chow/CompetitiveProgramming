#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <sstream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

std::unordered_map<string, int> mape;

int sum(string a, string c)
{
    int l = a.length();
    int thisSum = 0;
    for (int i=0; i<l; i++)
    {
        thisSum+=abs((int)a[i] - (int)c[i]);
    }
    mape[c] = thisSum;
    return thisSum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a;
    cin >> a;
    string b;
    cin >> b;
    int totalSum = 0;
    int aL = a.length();
    int bL = b.length();
    int stoppingPoint = bL - aL;
    for(int i = 0; i <=stoppingPoint; i++)
    {
        //int ende = i+ aL;
        //cout << i << " " << ende << endl;
        string c = b.substr(i, aL); //substr is length
        if (mape.count(c) > 0)
        {
            totalSum+=mape[c];
            //cout << "map used!" << endl;
        }
        else
        {
        totalSum+= sum(a, c);
        }
    }
    cout << totalSum << endl;
}
