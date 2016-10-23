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
#include <unordered_map>
#include <iomanip>

using namespace std;
typedef vector<int, int> vii;
typedef vector<int> vi;
typedef pair<int, int> p;
typedef map<int, int> mii;
typedef map<string, int> msi;
typedef unordered_map<int, int> umii;
typedef unordered_map<string, int> umsi;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie();
    int teams; cin >> teams;
    int place = teams;
    priority_queue<long long> pq;
    vector<long long>
    //keep dequeuing while possible to find best position
    for(int i=0; i<teams; i++)
    {
        long long a, b;
        pq.push(b-a + 1);
    }
}
