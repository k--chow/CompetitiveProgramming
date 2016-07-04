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

struct Compare
{
	bool operator()(long long & a, long long & b)
	{
		return a > b;
	}
};


int main()
{
	while (1)
	{
		int n;
		cin >> n;
		if (n == 0) break;
		priority_queue<long long, vector<long long>, Compare> pq;
		for(int i=0; i<n; i++)
		{
			int m;
			cin >> m;
			pq.push(m);
		}

		long long sum = 0;
		while (!pq.empty())
		{
			long long a, b;
			a = pq.top();
			pq.pop();
			b = pq.top();
			pq.pop();
			//add to sum
			long long minisum = a + b;
			sum += minisum;
			//cout << minisum << endl;
			//if not empty put it back in
			if (!pq.empty())
			{
				pq.push(minisum);
			}
		}
		
		cout << sum << endl;
	}
}