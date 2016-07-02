#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <map>

using namespace std;

int main()
{
	while (1)
	{
		int n;
		cin >> n;
		if (n == 0) break;
		vector<int> stuff;
		for(int i=0; i<n; i++)
		{
			int m;
			cin >> m;
			stuff.push_back(m);
		}
		long long sum = 0;
		//sort(stuff.begin(), stuff.end());
		for(int i=0; i<n; i++)
		{
			cout << sum << endl;
			sum += (sum + stuff[i]);

		}
		cout << sum << endl;
	}
}