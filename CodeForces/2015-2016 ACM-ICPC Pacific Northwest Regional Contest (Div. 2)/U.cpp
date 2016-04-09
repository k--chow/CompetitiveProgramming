#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> p;
int m, n, b; //m is columns, n is rows

void loadEdges(vector< vector<p> > & arr)
{
    arr[0][0] = arr[n][m];
    arr[n][0] = arr[0][m];
    arr[0][m] = arr[n][0];
    arr[n+1][n+1] = arr[1][1];
}



int main()
{

    cin >> m >> n >> b;
    vector< vector<p> > arr(n);
    pair<int, int> arra[n+2][m+2] ;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            int a;
            cin >> a;
            arr[i].push_back(make_pair(a, 9));
        }


    }

    for(int i=0; i<n; i++)
    {
        for(int j=1; j<m; j++)
        {

        }


    }



}
