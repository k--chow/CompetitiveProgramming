#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, p, q;
    string s;
    cin >> n >> p >> q;
    cin >> s;
    int r = n % p; //remainder
    int r2 = n % q;
    int d = n/p;
    int d2 = n/q;

    if (n % p == 0)
    {
        int times = n/p;
        cout << times << endl;
        for(int i=0; i!=n; i+=p)
        {
            cout << s.substr(i, p) << endl;
        }
    }
    else if (n % q == 0)
    {
        int times = n/q;
        cout << times << endl;
        for(int i=0; i !=n; i+=q)
        {
            cout << s.substr(i, q) << endl;
        }
    }
    else if ((r + d) % q == 0) //divisible
    {
        cout << (d-r) + ((r+d)/q) << endl;
        for(int i=0;i < ((d-r)*p); i+=p)
        {
            cout << s.substr(i, p) << endl;;
        }

        for(int i=(d-r)*p; i != n; i+=q)
        {
            cout << s.substr(i, q) << endl;;
        }

    }/*
    else if ((r2 + d2) % p == 0) //divisible 5, 18
    {
        cout << (d2-r2) + ((r2+d2)/p) << endl;
        for(int i=0;i < ((d2-r2)*p); i+=q)
        {
            cout << s.substr(i, q) << endl;;
        }

        for(int i=(d2-r2)*q; i != n; i+=p)
        {
            cout << s.substr(i, p) << endl;;
        }

    }*/
    else
    {
        cout << "-1" << endl;
    }
}


