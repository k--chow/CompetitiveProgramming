#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <cstring>
#include <queue>
using namespace std;

//no visited, if its less than go, if not stop

int graph[183][183];//allocate memory once
//int visited[182][182];//visited
int r, c;
queue< pair<int, int> > q;

void bfs(int cnt, pair<int, int> l)// i and j current position
{
    //cout << "i: " << l.first << " j: " << l.second << " " << dist[l.first][l.second] << " " << cnt << endl;
    //visited[l.first][l.second] = 1;
    //if index is 1 - set to 0
    if (cnt <= graph[l.first][l.second])
    {
        //cout << i << " " << j << " " << dist[i][j] << " now " << cnt << endl;

        graph[l.first][l.second] = cnt;

    }

    //go up - increment, check if i is 0
    //if dist > cnt, set it to cnt
    if (l.first-1 != -1 && graph[l.first-1][l.second] > cnt)
    {
        //bfs(cnt+1, i-1, j);
        q.push(make_pair(l.first - 1, l.second));
        //visited[l.first-1][l.second] = 1;
    }
    //go down - increment, check if i is (r-1)
    if (l.first+1 != r && graph[l.first + 1][l.second] > cnt)
    {
        //bfs(cnt+1, i+1, j);
        q.push(make_pair(l.first + 1, l.second));
        //visited[l.first+1][l.second] = 1;
    }

    //go left - increment, check if j is 0
    if (l.second -1 != -1 && graph[l.first][l.second-1] > cnt)
    {
        //bfs(cnt+1, i, j-1);
        q.push(make_pair(l.first, l.second-1));
        //visited[l.first][l.second-1] = 1;
    }

    //go right - increment, check if j is (c-1)
    if (l.second + 1 != c && graph[l.first][l.second + 1] > cnt)
    {
        //bfs(cnt+1, i, j+1);
        q.push(make_pair(l.first, l.second+1));
        //visited[l.first][l.second+1] = 1;
    }


}

int main()
{
    //bfs with count
    int cases;
    cin >> cases;
    //one call or many
    for(int a=0; a<cases; a++)
    {
        cin >> r >> c;
        char b;
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                cin >> b;
                int d = b-'0';

                if (d == 1) {
                    q.push(make_pair(i, j));
                    graph[i][j] = d;
                }
                else
                {
                    graph[i][j] = 1000;
                }

            }
            //cout << endl;
        }
        int cnt = 0;
        //bfs(cnt, make_pair(i, j), q); //problem is it has to be bfs, not dfs
        //visited[i][j] = 1;
        int s = q.size();

        int nextCount = 0;

        while (!q.empty())
        {

        //code to count levels
        pair<int, int> next = q.front();
        q.pop();
        nextCount++;
        bfs(cnt, next);

        if (nextCount == s)
        {
            cnt++;
            nextCount = 0;
            s = q.size();
        }
        }

        //cout << "ARRAY: " << endl;
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                cout << graph[i][j] << " ";
            }
            cout << endl;
        }

    }

}
