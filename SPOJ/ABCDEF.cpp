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
//re-order the problem, binary search (lower and upper bound), brute force, sorting, tricky problem detail, big number long long
int main()
{
  int n; cin >> n;
  vi arr;
  for(int i=0; i<n; i++)
  {
    int e; cin >> e;
    arr.push_back(e);
  }
  //left-side
  vl left;
  for(int a=0; a<n; a++)
  {
    for(int b=0; b<n; b++)
    {
      for(int c=0; c<n; c++)
      {
        ll leftAns = (arr[a] * arr[b]) + arr[c];
        left.push_back(leftAns);
      }
    }
  }

  //right-side
  vl right;
  for(int f=0; f<n; f++)
  {
    for(int e=0; e<n; e++)
    {
      for(int d=0; d<n; d++)
      {
        //tricky d I forgot
        if (arr[d] == 0)  continue;
        ll rightAns = (arr[f] + arr[e]) * arr[d];
        right.push_back(rightAns);

      }
    }
  }
  sort(left.begin(), left.end());
  sort(right.begin(), right.end());
  ll ans = 0; //was it this?
  for(int i=0; i<left.size(); i++)
  {
    //cout << left[a] << " " << right[a] << endl;
    int lo = lower_bound(left.begin(), left.end(), right[i]) - left.begin();
    int hi = upper_bound(left.begin(), left.end(), right[i]) - left.begin();
    ans += (hi-lo);
    //this can help for the number of duplicates

  }
  cout << ans << endl;
}
