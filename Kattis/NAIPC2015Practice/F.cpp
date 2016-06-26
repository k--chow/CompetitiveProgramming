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
#include <set>
using namespace std;
//12:22
int main()
{
	//regular map
	//traverse and get odds
	map<string, int> map1;
	map<string, int> map2;
	map<string, int>::iterator it;
	int subs;
	cin >> subs;
	for(int i=0; i<subs; i++)
	{
		string in;
		cin >> in;
		it = map1.find(in);
		if (it == map1.end())
		{
			map1[in] = 1;
		}
		else
		{
			map1[in]++;
		}

	}

	for(int i=0; i<subs; i++)
	{
		string in;
		cin >> in;
		it = map2.find(in);
		if (it == map2.end())
		{
			map2[in] = 1;
		}
		else
		{
			map2[in]++;
		}

	}
	int ans = 0;
	
	//iterate both maps
	for(it = map1.begin(); it!=map1.end(); it++)
	{
		map<string, int>::iterator it2;
		it2 = map2.find(it->first);
		if (it2 != map2.end())
		{
			ans+=abs(map2[it->first] - map1[it->first]);
		}
		else
		{
			ans+=(map1[it->first]);
		}
	}

	for(it = map2.begin(); it!=map2.end(); it++)
	{
		map<string, int>::iterator it2;
		it2 = map1.find(it->first);
		if (it2 != map1.end())
		{
			//found
		}
		else
		{
			ans+=(map2[it->first]);
		}
	}

	cout << subs - (ans/2) << endl;

	 
	//map them seperately though
	//two maps, check if equal number

	//unequal number

	//if unfound, its 0, subtract, later divide by 2
	/*
	correct - 3
	wa - 1
	timelimit - 1

	wa - 1
	correct - 2
	timelimit - 2

	correct - 5
	wa - 0
	*/

}

//12:45