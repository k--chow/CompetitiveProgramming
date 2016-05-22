#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <unordered_map>
using namespace std;

int main()
{
   int cases;
   cin >> cases;
   for(int i=0; i<cases; i++)
   {
       string a;
       cin >> a;
       sort (a.begin(), a.end());
       long long b;
       cin >> b;
       while(b != 0)
       {
           b--;
           next_permutation(a.begin(), a.end());
       }
       cout << a << endl;
   }
}

