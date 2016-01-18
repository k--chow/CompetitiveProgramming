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

int main() {
    int cases;
    vector<int> ans;
    cin >> cases;
    for(int i=0; i< cases; i++)
    {
        int c;
        cin >> c;
        int total = 0;
        int five = 5;
        while (true)
        {
            if (c/five == 0)
            {
                break;
            }
            //do this
            total+=c/five;
            //increment
            five*=5;
        }
        ans.push_back(total);

    }
    for(int i=0; i <ans.size(); i++)
    {

        cout << ans.at(i) << endl;
    }
}


