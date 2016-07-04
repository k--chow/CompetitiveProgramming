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

int main()
{
	//while cin
	int N;
	while (scanf("%d", &N) != EOF)
	{
		//initialize stack, queue, and pq
		stack<int> s;
		queue<int> q;
		priority_queue<int> pq;
		bool stack = true, queue = true, priority = true;

		//while stack, while queue, while pq continue

		//1 put on, 2 take off, check outputs

		//if output off, turn it off
		for(int i=0; i<N;i++)
		{
			int action, value;
			cin >> action >> value;
			if (action == 1)
			{
				if (stack)
				{
					s.push(value);
				}

				if (queue)
				{
					q.push(value);
				}

				if (priority)
				{
					pq.push(value);
				}
			}
			else //check output of 2
			{//expected is value
				
				if (stack)
				{
					if (!s.empty() && s.top() == value)
					{

						s.pop();
					}
					else
					{
						stack = false;
					}
					
				}

				if (queue)
				{
					if (!q.empty() && q.front() == value)
					{
						
						q.pop();
					}
					else
					{
						queue = false;
					}
				}

				if (priority)
				{
					if (!pq.empty() && pq.top() == value)
					{
						pq.pop();
					}
					else
					{
						priority = false;
					}
					
				}
			}
		}
	
	//cout << stack << " " << queue << " " << priority << endl;

	//3 booleans stack, queue, pq
	int count = 0;

	if (stack) count++;
	if (queue) count++;
	if (priority) count++;

	//count it up

	//if none - impossible
	if (count == 0) cout << "impossible" << endl;

	//if > 1, not sure
	if (count > 1) cout << "not sure" << endl;

	//if 1, check stack queue or pq
	if (count == 1)
	{
		if (stack) cout << "stack" << endl;
		if (queue) cout << "queue" << endl;
		if (priority) cout << "priority queue" << endl;
	}

	}

}