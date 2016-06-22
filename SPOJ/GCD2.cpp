
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int GCD(int a, int b)
{
    if (b == 0)
    {return a;}
    return GCD(b, a%b);
}
int numberGCD(string a, int b)
{
    int r = 0;
    r+=(a[0] -'0')%b;
    for(int i=1; i<a.length(); i++)
    {
        r+= ((a[i] - '0')*10) % b;
    }return r % b;
}
int main()
{int cases;
    cin >> cases;
    for(int i=0; i < cases; i++)
    {
        int A,ans;string B;
        cin >> A >> B;
        if (A == 0)
        {cout << B << endl;}
        else if (B.length() > 5) {//B is greater
            cout << GCD(A, numberGCD(B, A)) << endl;
        }
        else if (B == 0){cout << A << endl;}
        else
        {
            int Aa = atoi(B.c_str());
            if (Aa > A)
            {
                cout << GCD(Aa, A) << endl;
            }
            else //A is larger
            {cout << GCD(A, Aa) << endl;
            }}}}