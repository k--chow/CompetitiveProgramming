#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
int main()
{
    int d;
    cin >> d;
    for(int i=0; i<d; i++)
    {
        long long n;cin >> n;long long m = n/2;long long ans = 0;long long a = ((n*(n+1)*(n+2))/6) + (m*(m+1)*((2*m)+1))/3;long long c = ((m*m) + m)/2;if (n % 2 == 0) ans = a-c;if (n % 2 != 0) ans = a+c;cout << ans << endl;
    }
}

//500B limit is dumb
