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


int main()
{
  std::ios::sync_with_stdio(false);
	cin.tie(NULL); //is it this?
  int cases; cin >> cases;
  for(int i=0; i<cases; i++)
  {
    vector<string> names;
    vector<string> realNames;
    vector<string> papers;
    int p, n; cin >> p >> n;
    string s;
    cin.ignore();
    for(int j=0; j<p; j++)
    {
      getline(cin, s);
      papers.push_back(s);
    }
    map<string, int> visited;
    for(int j=0; j<n; j++)
    {
      getline(cin, s);
      string temp = "";
      for(int k=0; k<s.size(); k++)
      {
        if (s[k] != ',' && s[k] != ' ') temp+= s[k];
      }
      names.push_back(temp);
      realNames.push_back(s);
      visited[s] = 0;
    }

    map<string, vector<string> > adjList;
    queue<string> q;
    for(int j=0; j<papers.size(); j++)
    {
      vector<string> connections;
      //parse through character by characters
      string current = "";
      string cPaper = papers[j];
      int commaCounter = 0;
      for(int k=0; k<cPaper.size(); k++)
      {
        if (cPaper[k] == ',')
        {
          commaCounter++;
          if (commaCounter % 2 == 0) {//even
            //check if inside
            connections.push_back(current);
            //then add it
            current = "";
          }
        } else if (cPaper[k] == ':')
        {
          //add and break
          connections.push_back(current);
          break;
        }
        if (cPaper[k] != ',' && cPaper[k] != ' ') current += cPaper[k];
      }
      //add to adjList
      for(int k = 0; k<connections.size(); k++)
      {
        for(int j=0; j<connections.size(); j++)
        {
          if (connections[k] != connections[j])
          {
              adjList[connections[j]].push_back(connections[k]);
              adjList[connections[k]].push_back(connections[j]);
          }
        }
      }
      //cout << adjList["ErdosP."].size() << endl;


    }
    q.push("ErdosP.");
    //run bfs
    while(!q.empty())
    {
      string cur = q.front();
      q.pop();
      for(int k=0; k<adjList[cur].size(); k++)
      {
        string neighbor = adjList[cur][k];
        if (visited[neighbor] == 0) {
          visited[neighbor] = visited[cur] + 1;
          q.push(neighbor);
        } else {
          visited[neighbor] = min(visited[neighbor], visited[cur] + 1);
        }
      }
    }
    cout << "Scenario " << i+1 << endl;
    for(int k=0; k<names.size(); k++)
    {
      if (visited[names[k]] == 0) {
        cout << realNames[k] << " infinity" << endl;
      } else {
        cout << realNames[k] << " " << visited[names[k]] << endl;
      }
    }


  }
}
