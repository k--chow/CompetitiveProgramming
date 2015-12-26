
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;


class PalindromePrime
{
     public:
        int count(int L, int R)
        {
            int ans = 0;
            int i=L;
            if (i == 1) i++;
               for(; i <=R; i++)
               {
                   bool prime = true;
                   //isPrime
                   for(int j=2; j<=i/2; j++)
                   {
                       if (i%j == 0)//not prime
                       {
                           prime = false;
                           break;
                       }
                   }

                   //isPalindrome
                   if (prime)
                   {
                       string a = to_string(i);
                       bool pal = true;
                       for(int z=0,x=a.length()-1;z != a.length()-1;z++, x--)
                       {
                           if (a[z] != a[x])
                           {
                               pal = false;
                           }
                       }
                       if (pal)
                       {
                           ans++;
                           cout << i;
                       }
                   }

               }
               return ans;
        }

};
