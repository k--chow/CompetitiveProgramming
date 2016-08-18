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

//must be consecutive, if previous taken, must take

//recursive backtracking
long long money[300000];
//long long currentMoney[300000];
int goal;
int N;

int main()
{

    cin >> N >> goal;
    for(int i=0; i<N; i++)
    {
        int value;
        cin >> value;
        money[i] = value;
    }
    //currentMoney[0] = 0;
    //cout << buy(0)<< endl;
    long long ans = 0;
    long long current = 0;
    int j = 0;
    for(int i=0; i<N; i++)
    {
        current += money[i];
        while (current > goal)
        {
            current -= money[j];
            j++;
        }
        ans = max(current, ans);

    }

    cout << ans << endl;
}


