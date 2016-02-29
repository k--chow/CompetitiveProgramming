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
 vector<string> ans;
 cin >> cases;
 for(int i=0; i<cases; i++)
 {
     int c, top, bottom;
     cin >> c;
     //get row
     int sum = 0, counter = 0, r;
     while (sum < c)
     {
         counter++;
         sum+=counter;

     }
     r = sum - c;
     //cout << counter << endl;
     if (counter % 2 == 0) //even 1/n to n/1
     {
         top = counter;
         bottom = 1;
         for(int j=0; j<r; j++)
         {
             bottom++;
             top--;
         }
     }
     else //odd n/1 to 1/n
     {
         top = 1;
         bottom = counter;
         for(int j=0; j<r; j++)
         {
             top++;
             bottom--;
         }

     }
     string answ = "TERM " + to_string(c) + " IS " + to_string(top) + "/" + to_string(bottom);
     ans.push_back(answ);
 }
 for(int i =0; i<ans.size(); i++)
 {
     cout << ans.at(i) << endl;
 }

}
