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
	int N;
	while (cin >> N)
	{
		long long sum = 0, ans = -1000000000;
		if (N == 0) break;
		for(int i=0;i< N; i++)
		{
			int in;
			cin >> in;
			sum += in;
			ans = max(sum, ans);
			if (sum < 0) sum = 0;
		}
		cout << ans << endl;

	}
	

}