#include <iostream>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <stack>
#include <list>
using namespace std;

class CorruptedMessage
{
	public:
		string reconstructMessage(string s, int k)
		{
            int n= s.size();
            int yes = n-k;
            string answer = "z";
            for (int i=0; i<n; i++)
            {
                size_t go = count(s.begin(), s.end(), s[i]);
                if (go == yes)
                {
                    answer = string(n, s[i]);
                    break;
                }
            }
            if (k==0)
            {
                return s;
            }
            else if(n == k)
            {
                return string(n, 'z');
            }
            else
            {
            return answer;
            }

        }
};


