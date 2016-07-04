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
int N, B;
int ans, weights[20], answer[20];
vector<int> arr;


void recurse(int currentItem, int currentWeight)
{
	//cout << currentItem << " " << currentWeight << endl;
	if (currentItem == B)
	{
		//cout << ans << endl;
		if (currentWeight > ans)
		{
			for(int i=0; i<arr.size(); i++)
			{
				answer[i] = weights[arr[i]];
			}
			//cout << endl;
			ans = currentWeight;

		}

		
	}

	for(int i=currentItem; i<B; i++)
	{
		if (currentWeight + weights[i] <= N)
		{
			arr.push_back(i);
			recurse(i+1, currentWeight + weights[i]);
			arr.erase(arr.begin() + arr.size() -1);
		}
	}
}

int main()
{
	while (cin >> N)
	{
		cin >> B;
		memset(weights, 0, sizeof(weights));
		for(int i=0; i<B; i++)
		{
			cin >> weights[i];
			//cout << weights[i];
		}
		ans = 0;
		memset(answer, 0, sizeof(answer));
		recurse(0, 0);

		for(int i=0; i<20; i++)
		{
			if (answer[i] != 0) cout << answer[i] << " ";
			
		}
		cout << "sum:" << ans << endl;

	}
}