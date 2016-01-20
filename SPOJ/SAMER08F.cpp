#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
using namespace std;

int answer(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return (n*n) + answer(n-1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> ans;
    while(1)
    {
        int c;
        cin >> c;
        if (c == 0)
        {
            break;
        }
        ans.push_back(answer(c));


    }
    for(int i=0;i <ans.size(); i++)
    {
        cout << ans.at(i) << endl;
    }

}
