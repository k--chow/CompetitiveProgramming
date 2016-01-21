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
    vector<int> ans;
    for(int i=0; i <cases; i++)
    {
        int n;
        cin >> n;
        int men[n];
        int women[n];
        //men
        for(int j=0; j<n; j++)
        {
            cin >> men[j];
        }
        //women
        for(int j=0; j<n; j++)
        {
            cin >> women[j];
        }
        std::sort(men, men+n);
        std::sort(women, women+n);
        int sum = 0;
        for(int j=0; j<n; j++)
        {
            sum+=men[j]*women[j];
        }
        ans.push_back(sum);

    }

    for(int i=0; i <ans.size(); i++)
    {
        cout << ans.at(i) << endl;
    }
}
