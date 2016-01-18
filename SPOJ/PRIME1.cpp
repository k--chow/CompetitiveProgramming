
#include <algorithm>
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;

void sieve(int a, int b)
{
    //don't store
    //test up to square root of 1 billion
    //test from 2 to sqrt(1,000,000,000)

    for(int i=a; i<=b; i++)
    {
        if (i == 1) continue;
        double c = int(sqrt(i));
        bool isPrime = true;
        for(int j=2; j<=c; j++)
        {
        if (i % j == 0)
        {
            isPrime = false;
            break;
        }

        }
        if (isPrime)
        {
            cout << i << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cases;
    cin >> cases;
    vector<int> ans;
    for(int i=0; i<cases; i++)
    {
        int a,b;
        cin >> a >> b;
        sieve(a, b);

    }

}

//actually use a sieve
