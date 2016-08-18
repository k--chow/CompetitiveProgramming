#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
using namespace std;

int main()
{
	int N, ans=0;
	cin >> N;
	map<int, int> mappy;
	map<int, int>::iterator it;
	vector<int> ff;
	for(int i=0; i<N; i++)
	{
		int id, f;
		cin >> id >> f;
		mappy[id] = 1;
		for(int j=0; j<f; j++)
		{
			cin >> id;
			ff.push_back(id);
		}

	}
	//cout << ff.size() << endl;

	for(int i=0; i<ff.size(); i++)
	{
		it = mappy.find(ff[i]);
		if (it == mappy.end())
		{
			ans++;
			mappy[ff[i]] = 1;
			//cout << ff[i] << " ";
		}
	}

	cout << ans << endl;

}