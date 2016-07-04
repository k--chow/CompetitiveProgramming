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
	long long ans;
	vector<long long> arr;
	arr.push_back(1);
	for(long long i=2; i<=1000001; i++)
	{
		arr.push_back(arr[i-2] + (i*(i+1))/2);
	}

	int N;
	while (cin >> N)
	{
		if (N ==0) break;
		
		cout << arr[N-1] << endl;
	}
}