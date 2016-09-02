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
int solutionCount, n;
vector<int> placed;

bool place(int r, int c)
{
	//check row
	//check column
	//check diagonal 
}

void recurse(int r)
{
	//if r == 8, solutionCount++;
	for(int c=0; c<n; c++)
	{
		//try to place
		//if possible, recurse again
		//remove placed
	}
}

int main()
{
	//recursive backtracking solution count
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		placed.push_back(-1);
	}
	solutionCount = 0;

}