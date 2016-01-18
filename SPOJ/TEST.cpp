#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio (false);
    int a;
    vector<int> ans;
    while (1)
    {
        cin >> a;
        if (a == 42)
        {
            //cout << "Found" << endl;
            break;
        }
        else
        {
        ans.push_back(a);
        }
    }

    for(int i=0; i< ans.size(); i++)
    {
        cout << ans.at(i) << endl;
    }
}
