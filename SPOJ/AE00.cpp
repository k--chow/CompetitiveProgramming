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

int calculate(int s, int n, int total)
{
    if (n == 1)
    {
        return 1;
    }
    else if (s == n+1)
    {
        return total;
    }
        total+=1;
        //s try factors from 2 to s/2
        int factors = 0;
        for(int i=2; i<=s/2; i++)
        {
            if (s%i == 0)
            {
                factors++;
            }
        }
        if (factors %2 == 0)
        {
            total+=factors/2;
        }
        else
        {
            total+=(factors/2)+1;
        }
        return calculate(s+1, n, total);

}

int main()
{
    int n;
    cin >> n;
    cout << calculate(2, n, 1) << endl;

}
