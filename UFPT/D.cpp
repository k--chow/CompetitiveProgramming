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
#include <iomanip>
#include <map>
using namespace std;
typedef vector< vector<int> > vii;
typedef pair<int, int> pii;
bool ans = true;
void dfs(vii &adjList, vector<int> & visited, int current, int count, int previous)
{
  visited[current] = count;
  for(int i=0; i<adjList[current].size(); i++)
  {
    int neighbor = adjList[current][i];
    if (visited[neighbor] == 0) {
      dfs(adjList, visited, neighbor, count+1, current);
    } else if (neighbor != previous) {
      //check cycle
      if ((count+1 - visited[neighbor]) % 2 != 0)
      {
        ans = false;
      }
    }
  }
}

int main()
{
  std::ios::sync_with_stdio(false);
	cin.tie(NULL); //is it this?
    int nodes;
    while (true){
      cin >> nodes;
      if (nodes == 0) break;
      int edges; cin >> edges;
      vii adjList(nodes);
      vector<int> visited(nodes, 0);
      for(int j=0; j<edges; j++)
      {
        int a, b; cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
      }
      //dfs
      dfs(adjList, visited, 0, 0, -1);
      //print
      if (ans) {
        cout << "BICOLORABLE." << endl;
      } else {
        cout << "NOT BICOLORABLE." << endl;
      }
      ans = true;
  }

}
