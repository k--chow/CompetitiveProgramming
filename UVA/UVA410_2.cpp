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

int main() {
	int C, S;
	int set = 0;
	while (cin >> C >> S)
	{
		set++;
		vector<int> store;
		vector<string> ans;
		double imbalance;
		double realImbalance = 0;
		for(int i=0; i<S; i++)
		{
			int S1;
			cin >> S1;
			store.push_back(S1);
			imbalance += S1;
		}
		imbalance /= C;
		//append if needed
		while (store.size() < 2*C)
		{
			store.push_back(0);
		}
		
		sort(store.begin(), store.end());
		cout << "Set #" << set << endl;


		for(int i=0; i<C; i++)
		{
			string a = "";
			double total = 0;
			if (store[i] != 0)
			{
				a += to_string(store[i]);
				a += " ";
				//realImbalance += fabs(store[i] - imbalance);
				total += store[i];
			}
			if (store[((2*C)-1)-i] != 0)
			{
				a += to_string(store[((2*C)-1)-i]);
				//realImbalance += fabs(store[((2*C)-1) -i] - imbalance);
				total += store[((2*C)-1) -i];
			}
			realImbalance += fabs(total - imbalance);
			ans.push_back(a);
			cout << " " << i << ": " << a << endl;
		}
		cout << "IMBALANCE = " << realImbalance << imbalance << endl;
		//store a string in vector
	}
}