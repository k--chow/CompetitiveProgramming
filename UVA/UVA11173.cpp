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
	int cases;
	cin >> cases;
	for(int i=0; i<cases; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << (b ^ (b >> 1)) << endl;
	}
}