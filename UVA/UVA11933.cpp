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
	//while int i % 2 odd to a, even to b, subtract it there.
	while (1)
	{
		int n, a=0, b=0, r;
		cin >> n;
		if (n == 0) break;
		int i=1; //index
		while (n != 0)
		{
			r = (n & -n);
			n-=r;
			if (i % 2 != 0)
			{
				a+=r;
			}
			else
			{
				b+=r;
			}
			i++;
		}

		cout << a << " " << b << endl;

	}
}