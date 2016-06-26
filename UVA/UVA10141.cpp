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
	int r, p, j=1;
	while(cin >> r >> p)
	{
		string null;
		if (r == 0 && p == 0) break;
		if (j != 1) cout << endl;
		string ansA = "swag";
		double ansB = -1;
		int ansC = -1;
		getline(cin, null);
		for(int i=0; i<r; i++)
		{
			
			getline(cin, null);
			//cout << null << endl;
		}
		for(int i=0; i<p; i++)
		{
			//take in object
			string a;
			double b;
			int c;
			getline(cin, a);
			cin >> b >> c;
			//cout << a << " " << b << " " << c << endl;
			getline(cin, null);
			for(int j=0; j<c; j++)
			{
				
				getline(cin, null); 
			}
			if (c > ansC)
			{
				ansA = a;
				ansB = b;
				ansC = c;
			}
			else if (c == ansC)
			{
				if (b < ansB)
				{
					ansA = a;
					ansB = b;
					ansC = c;
				}
			}
		}
		//print answer
		cout << "RFP #" << j << endl;
		cout << ansA << endl;
		j++;

	}

	//save requirements in array
	//save name, price, and proposed require as max if larger or cheaper
	//print it out after loop
}