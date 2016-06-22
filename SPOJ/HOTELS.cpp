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
int money[300000];
int goal;
int N;
long long buy(int currentChoice, long long currentMoney)//is previous bought?
{
    if (currentMoney > goal) { // can't buy
        //backtrack??
        return currentMoney - money[currentChoice -1];
    }
    if (currentChoice == N)
    {
        return currentMoney;
    }
    //cout << currentMoney << endl;
    if (currentMoney == goal) return currentMoney; // reached


    return max(buy(currentChoice+1, 0), buy(currentChoice+1, currentMoney + money[currentChoice]));//is this why it's not consecutive? yes.
    //if you skip, back to 0





}

int main()
{

    cin >> N >> goal;
    for(int i=0; i<N; i++)
    {
        int value;
        cin >> value;
        money[i] = value;
    }
    //for loop to buy max
    cout << buy(0, 0)<< endl;
}


