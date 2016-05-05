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

void solve(vector< vector<int> > & DP, int needed, int i, int j, int newHire, int sever, int current, int ending)
{

    //needed case
    if (j == needed)
    {
    int mini = 100000;
    //find min of (row above + getting to current state)
            for(int b=0; b<30; b++)
            {
                if (DP[i-1][b] != -1 )
                {
                    int above; //always adds up to the index j
                    int index = b; //current j column
                    if (index < needed)//keep current employees + add new ones
                    {
                        above = (needed-index)*newHire + (index*current);
                    }
                    else if (index == needed)
                    {
                        above = index*current;
                    }
                    else //index > needed
                    {
                        above = (needed*current) + ((index - needed)*sever);
                    }
                    int total = DP[i-1][b] + above;
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

    for(int c = j; c<=ending; c++)
    {
            int mini = 100000;
            //find min of (row above and across+ getting to current state) from above
            for(int b=c; b<=ending; b++)
            {
                if (DP[i-1][b] != -1 )
                {
                    int above;

                    if (b < c)
                    {
                        above = (c-b)*newHire + (b*current);
                    }
                    else if (b == c)
                    {
                        above = b*current;
                        //cout << "above: " << above;
                    }
                    else //b > c
                    {
                        above = (b * current) + (b - c) * sever; //what about other indexes?
                    }
                    int total = (DP[i-1][b] + above);
                    if (total < mini)
                    {
                        mini = total;
                    }

                    //cout << "above: " << (needed*current) + (index - needed)*sever << " " << b <<endl;

                }
            }
            DP[i][c] = mini;



    }
    }
}

int main()
{
    while (1)
    {
        vector< vector<int> > DP(30);
        for(int i=0; i<30; i++)
        {
            for(int j=0; j<30; j++)
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
            for(int a=0; a<30; a++)
            {
                if (DP[i-1][a] != -1) ending = a;
            }
            //now it begins, now it ends
            for(int j=n[i]; j<30; j++) //j starts at needed
            {
                    solve(DP, n[i], i, j, newHire, sever, current, ending);

            }
        }

        //cout << DP[months-1][n[months-1]];

        for(int i=0; i<months; i++)
        {
            //now it begins, now it ends
            for(int j=0; j<30; j++) //j starts at needed
            {
                    cout << DP[i][j] << " ";

            }
            cout << endl;
        }

    }











}
