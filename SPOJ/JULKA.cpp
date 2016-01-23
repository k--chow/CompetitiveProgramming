#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

string arrayToString(int a[], int s)
{
    string b = "";
    for(int i=0; i<s; i++)
    {

        b+= to_string(a[i]);
    }
    return b;
}

string subtract(int top[], int bot[], int s)
{
    int answer[s];
    for(int i=s-1; i>-1; i--)
    {
        int j=i;
        if (top[j] < bot[j])
        {
            j--;
            while(top[j] == 0)
            {
                j--;
            }
            while (j != i)
            {
                top[j]-=1;
                j++;
                top[j]+=10;
            }
        }
        answer[i] = top[i]-bot[i];
    }
    return arrayToString(answer, s);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> ans;
    for(int i=0; i<10;i++)
    {
        string a, b;
        cin >> a >> b;
        int c[a.length()+1], d[a.length()+1];
        //memset(c, 0, sizeof(c));
        //memset(d, 0, sizeof(c));
        while (b.length() != a.length())
        {
            b = "0" + b;
        }
        //put strings into arrays
        for(int j=0; j<a.length(); j++)
        {
            c[j] = a[j] - '0';
            //cout << c[j] << endl;

        }
        for (int j=0; j<b.length(); j++)
        {
            d[j] = b[j] - '0';
        }

        for(int j=0; j<a.length()+1; j++)
        {
            if (c[j] % 2 != 0 && j != a.length())
            {
                c[j+1]+=10;
            }
            c[j] = c[j]/2;
        }
        //divide d by 2
        for(int j=0; j<b.length()+1; j++)
        {
            if (d[j] % 2 != 0 && j != b.length())
            {
                d[j+1]+=10;
            }
            d[j] = d[j]/2;
        }

        //add them together
        string an = arrayToString(c, a.length()+1);
        string bn = arrayToString(d, b.length()+1);
        //cout << an << " " << bn << endl;
        int e[a.length()+1];
        //memset(e, 0, sizeof(e));
        for(int j = a.length(); j>-1; j--)
        {
            //cout << e[j] << endl;
            e[j]+=c[j] + d[j];
            if (e[j] > 9 && j != 0)
            {

              e[j] = e[j] % 10;e[j-1] = 1;

            }

        }
        string sn = subtract(c, d, a.length());

        string cn = arrayToString(e, a.length());
        //cout << cn << endl;
        while (cn[0] == '0' && cn.length() != 1)
        {
            cn = cn.substr(1);
        }
        while (sn[0] == '0' && sn.length() != 1)
        {
            sn = sn.substr(1);
        }
        ans.push_back(cn);
        ans.push_back(sn);
        //convert to string

    }
    for(int i=0; i <20; i++)
    {
        cout << ans.at(i) << endl;
    }
}
