#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>


using namespace std;
#define INF 99999999
#define MAX 300

void solve(vector< vector<long long> > & DP, int needed, int i, int j, int newHire, int sever, int current, int ending)
{

    //needed case
    if (j == needed)
    {
    int mini = INF;
    //find min of (row above + getting to current state)
            for(int c=0; c<=ending; c++)
            {
                if (DP[i-1][c] != -1 )
                {
                    int above; //always adds up to the index j

                    if (c < needed)//keep current employees + add new ones
                    {
                        above = (needed-c)*newHire + (c*current);
                    }
                    else if (c == needed)
                    {
                        above = c*current;
                    }
                    else //index > needed
                    {
                        above = (needed*current) + ((c - needed)*sever);
                    }
                    int total = DP[i-1][c] + above;
                    //cout << DP[i-1][b] << " " << above << endl;
                    if (total < mini)
                    {
                        mini = total;
                    }

                }


            }
            DP[i][j] = mini;
    }
    //loop the other cases
    else if (j <= ending && j > needed)
    {
    int mini = INF;
    for(int c = j; c<= ending; c++)
    {
        //find min of (row above and across + getting to current state) from above
        if (DP[i-1][c] != -1 )
        {
                    int above;
                    /*
                    if (b < c)
                    {
                        above = (c-b)*newHire + (b*current);
                    }*/
                    if (j == c)
                    {
                        above = j * current;
                        //cout << "above: " << above;
                    }
                    else //c > j
                    {
                        above = (j * current) + (c - j) * sever; //what about other indexes?
                    }
                    int total = (DP[i-1][c] + above);
                    if (total < mini)
                    {
                        mini = total;
                    }

                }


    }

    DP[i][j] = mini;
    }
}

int main()
{
    int counter = 1;
    while (1)
    {

        vector< vector<long long> > DP(MAX);
        for(int i=0; i<MAX; i++)
        {
            for(int j=0; j<25; j++)
            {
                DP[i].push_back(-1);
            }
        }
        int months;
        cin >> months;
        if (months == 0) break;
        int hire, current, sever;
        cin >> hire >> current >> sever;
        int newHire = hire+current;
        vector<int> n;
        for(int i=0; i<months; i++)
        {
            int employees_needed;
            cin >> employees_needed;
            n.push_back(employees_needed);
        }
        DP[0][n[0]] = newHire*n[0]; //implementation detail
        for(int i=1; i<months; i++)
        {
            int ending;
            //first find index of where to end (from previous)
            for(int a=0; a<MAX; a++)
            {
                if (DP[i-1][a] != -1) ending = a;
            }
            //now it begins, now it ends
            for(int j=n[i]; j<MAX; j++) //j starts at needed
            {
                    solve(DP, n[i], i, j, newHire, sever, current, ending);

            }
        }

        int ans = INF;
        for(int i=0; i<MAX; i++)
        {
            if (DP[months-1][i] != -1)
            {
                if (DP[months-1][i] < ans)
                {
                    ans = DP[months-1][i];
                }


            }

        }

        cout << "Case " << counter << ", cost = $" << ans << endl;
        counter++;


    }











}
