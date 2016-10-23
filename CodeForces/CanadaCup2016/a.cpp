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
//FIX THIS CODE LATER
/*
int travel(string p, int i, vi & visited)
{
    if (visited[i] == 0)
    {
        if (p[i] == '>')
        {
            if (i == p.size()-1)
            {
                return 1;
            } else {
                visited[i] = 2;
                return visited[i+1] = travel(p, i+1, visited);
            }
        } else if (p[i] == '<'){ // '<'
            if (i == 0)
            {
                return 1;
            } else {
                visited[i] = 2;
                return visited[i-1] = travel(p, i-1, visited);
            }
        }
    }
    return visited[i];
}

int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie();
  int l; cin >> l;
  string p; cin >> p;
  vi visited(l+1, 0); //0 unvisited, 1 fall, 2 not fall
  int ans = 0;
  for(int i=0; i<l; i++)
  {
      visited[i] = travel(p, i, visited);
      if (visited[i] == 1) ans++;
  }
  cout << ans << endl;
}*/

int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie();
  int l; cin >> l;
  string p; cin >> p;
  int ans = 0;
  if (p[0] == '<')
  {
      ans++;
      int i = 0;
      while (i <= p.size()-1)
      {
          i++;
          if (p[i] == '<') {
              ans++;
          } else {
              break;
          }
      }
  }

  if (p[p.size()-1] == '>')
  {
      ans++;
      int i = p.size()-1;
      while (i >= 0)
      {
          i--;
          if (p[i] == '>') {
              ans++;
          } else {
              break;
          }
      }
  }
  cout<< ans << endl;
}
