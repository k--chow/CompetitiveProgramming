
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <unordered_map>
#include <utility>
#include <iomanip> //for precision
#include <queue>
using namespace std;

typedef pair<int, int> P;
 /*
bool compare(int a, int b)
{
   return (a<b);
}
 */
//std::priority_queue<int, std::vector<int>, decltype(&compare)> pq1(&compare);

struct compare
{
    bool operator() (const pair<int, int> & a, const pair<int, int> & b)
    {
        return a.second > b.second;
    }
};

class CompareDist
{
public:
    bool operator()(pair<int,int> n1,pair<int,int> n2) {
        return n1.second>n2.second;
    }
};

int main()
{
	priority_queue< P ,std::vector< P >, compare> pq;
	pq.push(make_pair(1, 3));
	pq.push(make_pair(1, 2));

	while (!pq.empty()) {
    cout << pq.top().second << endl;   //print out the highest priority element
    pq.pop();                   //remove the highest priority element
    }

}
