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

//long long arr[100001];
long long tree[400001];
long long lazy[400001]; //lazy value needed for each element

void build_tree(int index, int left, int right)
{
	if (left > right) return;

	if (left == right) {
		tree[index] = 0;
		lazy[index] = 0;
		return;
	}

	build_tree((index*2) +1, left, (left+right)/2);
	build_tree((index*2) +2, ((left+right)/2) + 1, right);
	tree[index] = tree[(index*2)+1] + tree[(index*2)+2];
	lazy[index] = tree[index];
}

void update_tree(int index, int left, int right, int updateLeft, int updateRight, int value)
{
	//check if update needed and update
	if (lazy[index] != 0)
	{
		tree[index] += lazy[index];
		if (left != right)
		{
			lazy[(index*2) +1] += lazy[index];
			lazy[(index*2) + 2] += lazy[index];
		}
		lazy[index] = 0;
	}
	if (left > right || left > updateRight || right < updateLeft) return;

	if (left == right) {
		tree[index] += value;
		return;
	}

	update_tree((index*2)+1, left, (left+right)/2, updateLeft, updateRight, value);
	update_tree((index*2) + 2, ((left+right)/2) + 1, right, updateLeft, updateRight, value);

	tree[index] = (tree[(index*2) + 1] + tree[(index*2) + 2]);
}

long long query_tree(int index, int left, int right, int updateLeft, int updateRight)
{
	//check if update needed
	if (lazy[index] != 0) {
		tree[index] += lazy[index];
		if (left != right)
		{
			lazy[(index*2)+1] += lazy[index];
			lazy[(index*2) + 2] += lazy[index];
		}
		lazy[index] = 0;
	}
	//update, delegate if a range to children
	//reset the lazy of this index to 0
	if (left > right || left > updateRight || right < updateLeft) return 0;
	if (left >= updateLeft && right <= updateRight) {
		return tree[index];
	}
	return query_tree((index*2)+1, left, (left+right)/2, updateLeft, updateRight) +
		query_tree((index*2) + 2, (left+right)/2 + 1, right, updateLeft, updateRight);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int cases;
	cin >> cases;
	for(int i=0; i<cases; i++)
	{
		int N, C;
		cin >> N >> C;
		build_tree(0, 0, N-1);
		for(int j=0; j<C; j++)
		{
			long long type, p, q, v;
			cin >> type >> p >> q;
			p--;
			q--;
			if (type == 0)
			{
				cin >> v;
				update_tree(0, 0, N-1, p, q, v);
			}
			else
			{
				cout << query_tree(0, 0, N-1, p, q) << endl;
			}
		}
	}
}