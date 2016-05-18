#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>
#include <iomanip>
using namespace std;

typedef pair<pair<int, int>, int> p;
typedef vector<int> vi;
typedef vector<vi> vii;

#define PI 3.14159265

int main()
{
    int cases;
    cin >> cases;
    for(int i=0; i<cases; i++)
    {
        long long thirdTerm, thirdLast, sum;
        cin >> thirdTerm >> thirdLast>> sum;
        long long n = (sum * 2 )/(thirdTerm + thirdLast);
        long long d = (thirdLast - thirdTerm)/(n-5);
        cout << n << endl;
        long long start = thirdTerm - (2*d);
        for(int j=0; j<n; j++)
        {
            cout << start + (j*d) << " ";
        }
        cout << endl;
    }
}
