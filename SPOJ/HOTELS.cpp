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

//if currentMoney[currentChoice-1] + money[currentChoice] > goal - return 0;
//if currentChoice == N return;
//if currentMoney[currentChoice-1] + money[currentChoice] - return self
//currentMoney[] 

//4 5 1 0 3 1

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
    for(int i=0; i<N; i++)
    {
        current += money[i];
        if (current > goal)
        {
            ans = max(ans, current -= money[i]);
            current = 0;
        }
    }

    cout << ans << endl;
}


