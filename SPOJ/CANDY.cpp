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
    vector<int> ans;

    while (1)
    {
        int cases;
        cin >> cases;
        vector<int> store;
        if (cases == -1)
        {
            break;
        }
        int total = 0;
        for(int i=0; i<cases; i++)
        {
            int c;
            cin >> c;
            store.push_back(c);
            total +=c;
        }
        if (total % cases != 0)
        {
            ans.push_back(-1);
        }
        else
        {
            int error = total/cases;
            int totalError = 0;
            for(int i=0; i<cases; i++)
            {
                totalError += abs(store.at(i) - error);
            }
            ans.push_back(totalError/2);
        }
    }
    for(int i=0; i <ans.size(); i++)
    {
        cout << ans.at(i) << endl;
    }
}
