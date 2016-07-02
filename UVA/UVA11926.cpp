#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bitset>
using namespace std;
int main()
{
	bitset<(1 << 20)> foo;
	int n, m;
	while (1)
	{
		bool conflict = false;;
		foo.reset();
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		for(int i=0; i<n; i++)
		{
			int a, b;
			cin >> a >> b;
			for(int j=a; j<b; j++)
			{
				if (foo[j] == 1)
				{
					conflict = true;
					break;
				}
				foo.set(j);
			}
		}
		for(int i=0; i<m; i++)
		{
			int c, d, e, j=0;
			cin >> c >> d >> e;
			
			while (j <= 1000000 && !conflict)
			{
				j = c;
				for(; j<d; j++)
				{
				if (foo[j] == 1)
				{
					conflict = true;
					break;
				}
					foo.set(j);
				}

				c+=e;
				d+=e;
			}
			

		}

		if (conflict)
		{
			cout << "CONFLICT" << endl;
		}
		else
		{
			cout << "NO CONFLICT" << endl;
		}
	}

	return 0;
}

//subtract 1 from ends
//mark all places
//now mark repeats