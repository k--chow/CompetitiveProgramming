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
  int nodes, edges; cin >> nodes >> edges;
  vector< vector<int> > adj(nodes);
  vector<int> degree(nodes, 0);
  for(int i=0; i<edges; i++)
  {
    int u, v; cin >> u >> v;
    adj[u-1].push_back(v-1);
    degree[v-1]++;
  }
  vector<int> top;
  string topo = "";
  for(int i=0; i<nodes; i++)
  {
    int p; cin >> p;
    top.push_back(p);
    topo+= to_string(p);
  }
  //vector<int> visited(nodes, 0); no need for DAG
  set<int> setty;
  for(int i=0; i<nodes; i++)
  {
    if (degree[i] == 0)
    {
      setty.insert(i);
      //cout << i << "found" << endl;
    }
  }
  string ans = "";
  int state = 1;
  int index = -1;
  int hi;
  set<int>::iterator it;
  //find index first
  while (1)
  {

    //keep querying highest
    hi = topo[index] - '0' - 1;
    for(it=setty.begin(); it!= setty.end(); it++)
    {
      hi = max(hi, *it);
    }
    if (hi > topo[index] - '0' - 1)
    {
          index++;
    } else {
      break;
    }
  }

  if (index == 0) {
    cout << "-1" << endl;
  } else
  {
    index--;
    int j = 0;
    while (1)
    {
      //cout << state << endl;

      if (state == 1)
      {
        if (j != index)
        {
          hi = topo[j] - '0' - 1;
          //cout << "hi " << hi << endl;
        }

        else
        {
          state = 2;
        }
      }

      else //state 3
      {
        hi = 10001;
        for(it=setty.begin(); it!= setty.end(); it++)
        {
          hi = min(hi, *it);
        }
      }

      if (state == 2)
      {
          hi = (topo[index] - '0' - 1);
          for(it = setty.begin(); it!= setty.end(); it++)
          {
            if (*it > (topo[index] - '0' - 1))
            {
              hi = *it;
              break;
            }
          }

          for(it = setty.begin(); it!= setty.end(); it++)
          {
            if (*it > (topo[index] - '0' - 1))
            {
              hi = min(hi, *it);
            }
          }



          state = 3;
      }
      //remove degrees
      setty.erase(hi);
      for(int i=0; i<adj[hi].size(); i++)
      {
        degree[adj[hi][i]]--;
        if (degree[adj[hi][i]] < 1) setty.insert(adj[hi][i]);
      }
      ans += to_string(hi+1);
      j++;
      if (ans.size() == nodes) break;

    }

    for(int n=0; n<ans.length(); n++)
    {
      cout << ans[n] << " ";
    }

  }


}
