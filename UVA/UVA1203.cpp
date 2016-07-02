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

struct comparePair{

bool operator()(pair<int, int>& a, pair<int, int>& b)
{
	if (a.second > b.second)
	{
		return true;
	}
	else if (a.second < b.second)
	{
		return false;
	}
	else
	{
		return a.first > b.first;
	}
}

};

int main()
{
	//priority heap

	//time, tiebreaker is value (sorted)

	//K queries then done

	//increment by the smallest value, then sort
	//200, 300, 500 - 300, 0, 200

	//sort triples (n, value, current_value)

	//struggle to grasp how to sort them in intervals
	//(ID, value)
	priority_queue< pair<int, int>, vector< pair<int, int> >, comparePair>  pq;
	
	map<int, int> store;
	while(1)
	{
		string a;
		int b, c;
		cin >> a;
		if (a == "#") break;
		cin >> b >> c;
		store[b] = c;
		pq.push(make_pair(b, c));

	}

	int d;
	cin >> d;
	int i = 1;
	while (i <= d)
	{
		cout << pq.top().first << endl;
		pair< int, int> temp = pq.top();
		pq.pop();
		pq.push(make_pair(temp.first, temp.second + store[temp.first]));

		i++;
	}


}