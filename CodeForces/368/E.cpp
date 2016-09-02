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
#include <time.h>
#include <set>

using namespace std;

int main()
{
  int n, m, k; cin >> n >> m >> k;
  long long arr[n][m]; //2D
  map<int, bool> off;
  vector< vector< pair< pair<int, int>, int > > > garlands(k);
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<m; j++)
    {
      arr[i][j] = 0;
    }
  }

  for(int a=0; a<k; a++)
  {
    int s; cin >> s;
    off[a] = true;
    for(int b=0; b<s; b++)
    {
      int i,j,w; cin>>i>>j>>w;
      //set on 2D prefix array
      arr[i-1][j-1] =  w;
      //add to 2D array of garlands
      garlands[a].push_back(make_pair(make_pair(i-1, j-1), w));

    }

  }
  /*
  cout << endl;
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<m; j++)
    {
      cout << arr[i][j] << "     ";
    }
    cout << endl;
  }*/

  //prefix array
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<m; j++)
    {
      if (i == 0 && j == 0) {
        continue;
      }
      else if (i == 0) {
        arr[i][j] += arr[i][j-1];
      } else if (j == 0)
      {
        arr[i][j] += arr[i-1][j];
      }
      else
      {
        arr[i][j] += (arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1]);
      }
    }
  }

  set<int> offy;
  set<int>::iterator it;
  long long ans;
  /*
  cout << endl;
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<m; j++)
    {
      cout << arr[i][j] << "     ";
    }
    cout << endl;
  }*/
  //operations
  int ops; cin >> ops;
  for(int i=0; i<ops; i++)
  {
    //cout << i << endl;
    string op; cin >> op;
    if (op == "SWITCH")
    {
      int g; cin >> g;
      if (off[g-1] == true)
      {
        off[g-1] = false;
        offy.insert(g-1);
      } else {
        off[g-1] = true;
        offy.erase(g-1);
      }

    } else {
      ans = 0;
      int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
      //cout << offy.size() << endl;
      x1--; y1--; x2--; y2--;
      ans += arr[x2][y2];
      if (x1 > 0) ans-= arr[x1 - 1][y2]; //cout << arr[x2 - x1][y2] << endl;
      if (y1 > 0) ans-= arr[x2][y1 - 1]; //cout << arr[x2][y2 - y1] << endl;
      if (x1 > 0 && y1 > 0) ans+= arr[x1 - 1][y1 - 1]; //cout << arr[x2 - x1][y2 - y1] << endl;

      for(it = offy.begin(); it != offy.end(); it++)
      {
        //cout << "Size: " << offy.size() << endl;
        int o = *it;
        for(int j=0; j<garlands[o].size(); j++)
        {
          //get the pair, check if its in boundaries
          int x = garlands[o][j].first.first, y = garlands[o][j].first.second;
          if (x >= x1 && y >= y1 && x <= x2 && y <= y2)
          {
            ans -= garlands[o][j].second;
            //cout << "Found" << endl;
          }
        }
      }

      cout << ans << endl;

    }

  }



}
