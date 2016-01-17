
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void revers(string a, string& c)
{
    for(int i=0, j=a.length()-1; i<a.length(); i++, j--)
    {
        c[j] = a[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cases;
    vector<int> ans;
    cin >> cases;
    for(int i=0; i<cases; i++)
    {
        string a, b;
        cin >> a >> b;
        string c('a', a.length()), d('b', b.length());
        revers(a, c);
        revers(b, d);
        int e = atoi(c.c_str());
        int f = atoi(d.c_str());
        int g = e+f;
        string h = to_string(g);
        string j('a', h.length());
        revers(h, j);
        int k = atoi(j.c_str());
        ans.push_back(k);


    }
    for(int i=0; i<ans.size(); i++)
    {
        cout << ans.at(i) <<endl;
    }


}


