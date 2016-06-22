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

int main()
{
   int cases;
   cin >> cases;
   for(int i=0; i<cases; i++)
   {
       int goal, bars;
       cin >> goal >> bars;
       vector<int> barsArr;
       for(int j=0; j<bars; j++)
       {
           int bar;
           cin >> bar;
           barsArr.push_back(bar);
       }
       bool yes = false;
       //now we set
       for(int N=0; N < 1 << bars; N++)
       {
           int sum=0;
           for(int j=0; j<bars; j++)
           {
               if (N & (1<<j)) sum += barsArr[j];
           }
           if (sum == goal)
           {
               cout << "YES" << endl;
               yes = true;
               break;
           }
       }
       if (!yes) cout << "NO" << endl;
   }
}
