#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <unordered_map>
using namespace std;

int main()
{
	int cases;
	cin >> cases;
	for(int i=0; i<cases; i++)
	{
		int pieces, order;
		cin >> pieces >> order;
		if (order == 0)
		{
			cout << "Airborne wins." << endl;
		}
		else
		{
			cout << "Pagfloyd wins." << endl;
		}
	}
}