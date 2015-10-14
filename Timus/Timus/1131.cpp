#include <iostream>
#include <stdio.h>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;
    scanf("%i %i", &n, &k);
    int start = 1;
    int hours = 0;
    while(true)
    {
        if (start >= n)
        {
            break;
        }
        else if (start<= k)
        {
            hours++;
            start*=2;
        }
        else
        {
            int z = n-start;

            double a = (double)z/(double)(k);

            int yes = ceil(a);

            hours+=yes;
            break;
        }

    }
    printf("%i", hours);
}
