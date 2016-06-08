#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
using namespace std;

int main()
{int c;cin >> c;
    for(int i=0; i<c; i++)
    {string a;long long b;cin >> a >> b;int n = a[a.length()-1]-'0';vector<int> d;int n1 = n;while (1)
        {bool f = 0;for(int k=0; k<d.size(); k++)
            {if (d[k] == n1){f = 1;break;}}
            if (f) break;d.push_back(n1);n1*=n;string n2 = to_string(n1);n1 = n2[n2.length()-1] -'0';
        }int ans;if (b==0){ans=1;}else if (d.size() == 1){ans=d[0];}else if (b % d.size() == 0)
        {ans = d[d.size()-1];}
        else{ans=d[(b % d.size()) -1];}cout << ans << endl;
    }}




