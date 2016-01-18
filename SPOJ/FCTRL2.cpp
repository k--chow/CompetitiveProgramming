#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
using namespace std;
//proprocessor stuff
//reverse a string
void revers(string a, string& c)
{
    for(int i=0, j=a.length()-1; i<a.length(); i++, j--)
    {
        c[j] = a[i];
    }
}

string bigInteger(string a, int b)
{
    for(int i=a.size()-1; i>-1; i++)
    {
        string p1 = to_string(atoi(a[i].c_str()) * b);
        for(p1.length)
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cases;
    vector<string> ans;
    cin >> cases;
    for (int i=0; i <cases; i++)
    {
        __int128 total = 1;
        int c;
        cin >> c;
        for(int j=1; j<=c; j++)
        {
            total*=j;
        }
        ans.push_back(total);

    }
    for(int i=0; i<ans.size(); i++)
    {
        cout << ans.at(i) << endl;
    }
}
