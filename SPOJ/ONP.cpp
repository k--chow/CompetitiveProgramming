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
    stack<char> operators;
    vector<string> ans;
    int cases;
    cin >> cases;
    for(int i=0; i<cases; i++)
    {
        string c;
        cin >> c;
        string a = "";
        for(int j=0; j<c.length(); j++)
        {
            if (c[j] == ')')
            {
                char o = operators.top();
                a+=o;
                operators.pop();
            }
            else if (c[j] == '(')
            {
                continue;
            }
            else if (c[j] == '^' || c[j] == '/' || c[j] == '*' || c[j] == '-' || c[j] =='+')
            {
                operators.push(c[j]);
            }
            else
            {
                a+=c[j];
            }
        }
        ans.push_back(a);

    }
    for(int i=0; i<ans.size(); i++)
    {
        cout << ans.at(i) << endl;
    }
}
