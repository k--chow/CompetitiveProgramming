#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <unordered_map>
#include <map>
#include <queue>
using namespace std;
map< int, vector<int> > adj;
map<int, int> visited;
map<int, int> dist;

bool diff(int a, int b)
{
    string x = to_string(a);
    string y = to_string(b);
    int diff = 0;
    for(int i=0; i<4; i++)
    {
        if (x[i] != y[i]) {
            diff++;
        }
        if (diff > 1) return false;
    }
    if (diff == 1) return true;
    return false;
}

void dijkstra(int s, int d)
{
    visited[s] = 1;
    dist[s] = 0;
    queue<int> q;
    for(int i=0; i<adj[s].size(); i++)
    {
        //if unvisited
        q.push(adj[s][i]);
        if ((dist[s] + 1) < dist[adj[s][i]]) dist[adj[s][i]] = dist[s] + 1;
    }

    while (!q.empty())
    {
        int next = q.front();
        q.pop();
        visited[next] = 1;
        for(int i=0; i< adj[next].size(); i++)
        {
            if (visited[adj[next][i]] == 0)
            {
                q.push(adj[next][i]);
            }
            if ((dist[next] + 1) < dist[adj[next][i]]) dist[adj[next][i]] = dist[next] + 1;
            if (visited[d]) break;
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie();
    vector<int> primes;
    for(int p=1000; p<10000; p++)
    {
        bool isPrime = true;
        for(int j= 2; j< sqrt(p) + 1; j++)
        {
            if (p % j == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            primes.push_back(p);
            visited[p] = 0;
            dist[p] = 1000000;
        }

    }
    for(int i=0; i<primes.size(); i++)
    {
        int prime = primes[i];
        for(int j=0; j<primes.size(); j++)
        {
            if (diff(prime, primes[j])) {
                if (adj.count(prime) == 0) {
                    adj[prime];
                 }
                    adj[prime].push_back(primes[j]);

                
                
            }
        }
    }
    
    int cases; cin >> cases;

    for(int i=0; i<cases; i++)
    {
        int s, d; cin >> s >> d;
        for(auto& j : visited) {
            j.second = 0;
        }
        for(auto& j : dist) {
            j.second = 1000000;
        }
        //check if s or d are not possible
        if (adj.count(s) == 0 || adj.count(d) == 0)
        {
            cout << "Impossible" << endl;
        } else {
        dijkstra(s, d);
        cout << dist[d] << endl;
        }


    }
 }
