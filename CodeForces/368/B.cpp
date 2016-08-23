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
using namespace std;

int main()
{
  int n, m, k; cin >> n >> m >> k;
  vector< vector< pair<int, int> > > adj(n);
  map<int, bool> st;
  for(int i=0; i<m; i++)
  {
    int f, t, d; cin >> f >> t >> d;
    if (f != t) {
    adj[f-1].push_back(make_pair(t-1, d));
    adj[t-1].push_back(make_pair(f-1, d));
  }

  }

  for(int i=0; i<k; i++)
  {
    int s; cin >> s;
    st[s-1] = true;
  }
  int ans = 1000000001;
  bool set = false;

  for(int i=0; i<n; i++)
  {
    for(int j=0; j<adj[i].size(); j++)
    {
      if (st.count(i) == 1)//is storage
      {
        //cout << "one previous" << endl;
        if (st.count(adj[i][j].first) == 0)//edge from storage to city
        {
          //cout << "found edge" << endl;
          if (adj[i][j].second <= ans)
          {
            ans = adj[i][j].second;
            set = true;
          }
        }
      } else {
        break;
      }
    }
  }

  if (set) {
    cout << ans << endl;
  } else {
    cout << "-1" << endl;
  }
}
