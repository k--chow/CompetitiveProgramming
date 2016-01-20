#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> ans;
    while(true)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0 && b == 0)
        {
            break;
        }

        if (c-b == b-a)
        {
            int d = c + (b - a);
            string e = "AP " + to_string(d);
            ans.push_back(e);
        }

        else
        {
            int d = c * (b/a);
            string e = "GP " + to_string(d);
            ans.push_back(e);
        }


    }

    for(int i=0; i< ans.size(); i++)
    {

        cout << ans.at(i) << endl;
    }
}
