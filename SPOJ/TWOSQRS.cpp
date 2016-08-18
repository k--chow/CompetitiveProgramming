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
vector<long long> squares;

bool isTwoSquares(long long n)
{
	for(int i=0; i<squares.size(); i++)
	{
		if (squares[i] > n) return false;
		//binary search
		long long goal = n - squares[i];
		if (goal == 0) return true;
		if (binary_search(squares.begin(), squares.end(), goal)) return true;
	}
	return false;
}

int main() {
	for(long long i=0; i<=1000001; i++)
	{
		long long square = i*i;
		squares.push_back(square);
	}
	int cases;
	cin >> cases;
	for(int i=0; i<cases; i++)
	{
		long long c;
		cin >> c;
		if (isTwoSquares(c))
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
}
/*
bool isTwoSquares(int n)
{
	for(int i=0; i<squares.size(); i++)
	{
		if (squares[i] > n) return false;
		for(int j=0; j<squares.size(); j++)
		{
			long long current = squares[i] + squares[j];
			if (current > n) {
				break;
			} else if (current == n) {
				return true;
			}

		}
	}
	return false;
}

int main()
{
	int i=0;
	long long j = i*i;
	long long max = 1000000000000;

	while (j <= max)
	{
		squares.push_back(j);
		i++;
		j = i*i;
	}
	cout << i << endl;

	int cases;
	cin >> cases;
	for(int k=0; k<cases; j++)
	{
		int c;
		cin >> c;
		cout << isTwoSquares(c) << endl;
	}
}*/
