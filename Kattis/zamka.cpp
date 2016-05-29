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

int getSum(int a)
{
    int sum = 0;
    string ab = to_string(a);
    //cout << ab << endl;
    for(int i=0; i<ab.length(); i++)
    {
        sum += ab[i] - '0';
    }
    return sum;
}

int main()
{
    int L, D, X;
    int ans1, ans2;
    cin >> L >> D >> X;
    //start from lowest, literally increment to highest
    for(int i=L; i<=D; i++)
    {
        if (getSum(i) == X) {
        ans1 = i;
        break;
        }
    }

    //start frmo highest, literally increment to lowest
    for(int i=D; i>=L; i--)
    {
        if (getSum(i) == X) {
        ans2 = i;
        break;
        }
    }
    cout << ans1 << endl;
    cout << ans2 << endl;
}
