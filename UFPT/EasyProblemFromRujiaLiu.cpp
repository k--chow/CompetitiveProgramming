#include <algorithm>
#include <vector>
#include <tuple>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <queue>
#include <unordered_map>
using namespace std;

int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        unordered_map<int, vector<int> > e;
        for(int i=0; i<n; i++)
        {
            int elem; cin >> elem;
            e[elem].push_back(i+1);
        }
        for(int i=0; i<m; i++)
        {
            int k, el; cin >> k >> el;
            if (e.count(el))
            {
                if (k > e[el].size())
                {
                    cout << "0" << endl;
                } else {
                    cout << e[el][k-1] << endl;;
                }
            } else {
                cout << "0" << endl;
            }
        }
    }
}
