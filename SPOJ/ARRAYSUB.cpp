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
#include <queue>
#include <deque>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

int main()
{
	int n, k;
	cin >> n;
	vector<int> arr;
	for(int i=0; i<n; i++)
	{
		int e;
		cin >> e;
		arr.push_back(e);
	}
	cin >> k;
	deque<pii> dq;//use a pair instead
	dq.push_front(make_pair(-1, -1));
	int i=0;
	//initial loop
	for(;i<k; i++)
	{
		while (!dq.empty()) 
		{
			if (arr[i] >= dq.back().first) {
				dq.pop_back();
			} else {
				break;
			}
			
		}
		dq.push_back(make_pair(arr[i], i));
	}
	cout << dq.front().first << " ";
	//while i isn't end
	while (i < n)
	{
		if (i - dq.front().second == k) { //should be ok just once
			dq.pop_front();
		}
		while (!dq.empty()) 
		{
			if (arr[i] >= dq.back().first) {
				dq.pop_back();
			} else {
				break;
			}
		}
		dq.push_back(make_pair(arr[i], i));
		cout << dq.front().first << " ";
		i++;
	}
	//check if front's time is up, if so pop it *? if i-pairedi == k
	//try the other end pop until dq element is larger or equal
	//print out ans (front)
	//iterate i


}