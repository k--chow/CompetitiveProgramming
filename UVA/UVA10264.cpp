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
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int N;
	
	while (cin >> N)
	{

	vector<long long> sum((1 << N), 0 );
	for(int i=0; i< (1 << N); i++)
	{
		int x;
		cin >> x;
		for(int j=0; j < (1 << N); j++)
		{
			int n = i ^ j;//XOR
			if ((n & (-n)) == n && i != j)
			{
				sum[j]+=x;
			}
		}
		
	}
	long long maximum = 0;
	for(int i=0; i< (1 << N); i++)
	{
		for(int j=0; j<(1<<N); j++)
		{
			int n = i ^ j;
			if ((n & (-n)) == n && i != j)
			{
				maximum = max(maximum, sum[i] + sum[j]);
			}
		}
	}

	cout << maximum << endl;
	}
	return 0;
}