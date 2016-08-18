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

typedef long long ll;
typedef vector <int> vi;
typedef vector <long long> vl;

int main()
{
  int cases; cin >> cases;
  for(int i=0; i<cases;i++)
  {
    int n1; cin >> n1;
    vi arr1;
    for(int j=0; j<n1; j++)
    {
      int e; cin >> e;
      arr1.push_back(e);
    }
    int n2; cin >> n2;
    vi arr2;
    for(int j=0; j<n2; j++)
    {
      int e; cin >> e;
      arr2.push_back(e);
    }

    sort(arr2.begin(), arr2.end());
    int runningMin = 1000000000;
    for(int j=0; j<n1; j++)
    {
      int index = lower_bound(arr2.begin(), arr2.end(), arr1[j]) - arr2.begin();
      //cout <<"Index: " << index << arr1[j] << " " << arr2[index] << endl;
      if (arr1[j] == arr2[index]) {
        runningMin = 0;
        break;
      } else {
        runningMin = min(runningMin, abs(arr1[j] - arr2[index]));
      }
    }
    cout << runningMin << endl;
  }
}
