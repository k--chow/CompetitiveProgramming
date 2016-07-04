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

string reverse(string a)
{
	string newString = "";
	for(int i=a.length()-1; i >=0; i--)
	{
		newString += a[i];
	}
	return newString;
}

bool isPalindrome(string input)
{
	bool p;
	string half;
	if (input.length() % 2 != 0)
		{
			half = input.substr(0, input.length()/2 + 1);
		}

		
		else
		{
			half = input.substr(0, input.length()/2);
		}

	string rev = reverse(half);
	if (rev == input.substr(input.length()/2, input.length()))
	{
		return true;
	}
	else
	{
		return false;
	}

}

int main()
{
	string input;
	while (cin >> input)
	{
		if (input == "0") break;
		string half;

		if (isPalindrome(input))
		{
			input = "0";
		}
		else
		{
			bool odd = false;
			//odd, even
			if (input.length() % 2 != 0)
			{
				half = input.substr(0, input.length()/2 + 1);
				odd = true;
			}

			
			else
			{
				half = input.substr(0, input.length()/2);
			}

			//left larger
			string reverseHalf = reverse(half);
			//cout << half << endl;
			long longHalf = atol(reverseHalf.c_str());
			string stringSecondHalf = input.substr(input.length()/2, input.length());
			long secondHalf = atol(stringSecondHalf.c_str());
			if (longHalf > secondHalf)
			{
				long ans = longHalf - secondHalf;
				cout << ans << endl;
			}
			else //not equal needs more work
			{
				half[half.length()-1]++;
				string longHalfA = half;
				string revLongHalfA = reverse(longHalfA);
				string inputTwo;
				if (odd)
				{
					inputTwo = longHalfA + revLongHalfA.substr(1);
				}
				else
				{
					inputTwo = longHalfA + revLongHalfA;
				}
				long longFull = atol(inputTwo.c_str());
				long inputLong = atol(input.c_str());
				cout << longHalfA << " " << revLongHalfA << endl;

			}

			//if not increment
		
		}

		

	}
}
