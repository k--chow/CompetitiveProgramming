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
    int cases;
    cin >> cases;
    vector<string> ans;
    for(int i=0; i <cases; i++)
    {
        int x, y;
        cin >> x >> y;
        if (y == x || y == x-2)
        {
            //odd
            if (x % 2 != 0)
            {
                ans.push_back(to_string(x+y-1));
            }
            else //even
            {
                ans.push_back(to_string(x+y));
            }

        }
        else
        {
            ans.push_back("No Number");
        }

    }
    for(int i=0; i< ans.size(); i++)
    {
        cout << ans.at(i) << endl;
    }

}
