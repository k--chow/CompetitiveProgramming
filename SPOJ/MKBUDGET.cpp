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

void solve(vector< vector<int> > & DP, int needed, int i, int j, int newHire, int sever, int current)
{
    int ending;
    //first find index of where to end
    for(int a=0; a<15; a++)
    {
        if (DP[i-1][a] != -1) ending = a;
    }

    cout << ending << endl;
    for(int c= j; c<ending; c++)
    {
        if (c == needed) //max it out
        {
            int mini = 100000;
            //find min of (row above + getting to current state)
            for(int b=0; b<15; b++)
            {
                if (DP[i-1][b] != -1 )
                {
                    int above;
                    int index = b;
                    if (index < needed)
                    {
                        above = (needed-index)*newHire + (index*current);
                    }
                    else if (index == needed)
                    {
                        above = index*current;
                    }
                    else //index > needed
                    {
                        above = (needed*current) + (index - needed)*sever;
                    }

                    if ((DP[i-1][b] + above) < mini)
                    {
                        mini = DP[i-1][b] + above;
                    }

                }


            }
            DP[i][c] = mini;





        }
        else //just bring it down No, also more on right
        {

            int mini = 100000;
            //find min of (row above + getting to current state)
            for(int b=c; b<ending; b++)
            {
                cout << "ok" << endl;
                if (DP[i-1][b] != -1 )
                {
                    int above;
                    int index = b;
                    if (index < needed)
                    {
                        above = (needed-index)*newHire + (index*current);
                    }
                    else if (index == needed)
                    {
                        above = index*current;
                    }
                    else //index > needed
                    {
                        above = (needed*current) + (index - needed)*sever;
                    }

                    if ((DP[i-1][b] + above) < mini)
                    {
                        mini = DP[i-1][b] + above;
                    }

                }
            }
            DP[i][c] = mini;


    }
}
}

int main()
{
    vector< vector<int> > DP(30);
    for(int i=0; i<30; i++)
    {
        for(int j=0; j<30; j++)
        {
            DP[i].push_back(-1);
        }
    }
    int hire = 400, current = 600, sever = 600;
    int newHire = hire+current;
    vector<int> n;
    n.push_back(11);
    n.push_back(9);
    n.push_back(10);
    n.push_back(14);
    n.push_back(9);
    n.push_back(9);
    n.push_back(13);
    n.push_back(15);
    DP[0][11] = newHire*11;
    for(int i=1; i<2; i++)
    {
        for(int j=0; j<15; j++)
        {
            if (j < n[i]) //don't do anything
            {

            }
            else
            {
                solve(DP, n[i], i, j, newHire, sever, current);
            }

        }
    }

    for(int i=0; i<8; i++)
    {
        for(int j=0; j<15; j++)
        {
            cout << DP[i][j] << " ";
        }
        cout << endl;
    }

}
