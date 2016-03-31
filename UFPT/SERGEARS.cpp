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
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> p;
typedef pair< vector<int>, int> p2;
//pair 2 - x coordinate, y coordinate, index in array, previous direction, radius

int gcd(int a, int b)
{
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

void queueMeUp()
{
    //set to visited

    //if not this index of current in array

    //check others, even if visited

    //if not visited, queue it
}

int main()
{
    int gears;
    cin >> gears;
    vector <p2> list;
    vector <int> visited;

    //store gears
    for(int i=0; i<gears; i++)
    {
        int x, y, r;
        cin >> x >> y>> r;
        vector<int> c;
        c.push_back(x);
        c.push_back(y);
        c.push_back(i);
        c.push_back(0); //set all previous to 0
        p2 gear(c, r);
        list.push_back(gear);
        visited.push_back(0);

    }

    //first gear go start with clockwise
    visited[0] = 1;
    list[0].first[3] = 1;

    deque<p2> q;
    //traverse list and find neighbors for first gear
     //base
        int x1 = list[0].first[0];
        int y1 = list[0].first[1];
        int r1 = list[0].second;

    for(int i=1; i<list.size(); i++)
    {

        //dist formula
        int x2 = list[i].first[0];
        int y2 = list[i].first[1];
        int r2 = list[i].second;
        double dist = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
        if (dist == r1 + r2) //its a neighbor
        {
            list[i].first[3] = 1; //reverse direction
            q.push_back(list[i]);
        }
    }
    bool jam = false;
    bool found = false;
    bool sameD = false;


    while (!q.empty())
    {
        //cout << "Loop" << endl;
        p2 next = q.front();
        q.pop_front();

        //set visited to direction
        bool clockwise = false;
        if (next.first[3] == 1)
        {
            visited[next.first[2]] = 2;
        }
        else
        {
            visited[next.first[2]] = 1;
            clockwise = true;
        }
        //queue next if unvisited, but check all neighbors for gear jam
        x1 = list[next.first[2]].first[0];
        y1 = list[next.first[2]].first[1];
        r1 = list[next.first[2]].second;
        for(int i=0; i<list.size(); i++)
        {
            //dist formula
        int x2 = list[i].first[0];
        int y2 = list[i].first[1];
        int r2 = list[i].second;
        double dist = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
        if (dist == r1 + r2) //its a neighbor
        {
            if (visited[i] == 0)
            {
                if (clockwise) list[i].first[3] = 1; //previous  direction which is current gear
                if (!clockwise) list[i].first[3] = 2;
                q.push_back(list[i]);
            }
            else //check for gear jam
            {
                //cout << "CHECKING " << list[i].first[0] << " " << list[i].first[1] << endl;
                int currentDirection = visited[i];
                if (clockwise && currentDirection == 1)//I am 1, but my neighbor is also
                {
                    jam = true;
                    break;
                }
                if (!clockwise && currentDirection == 2)
                {
                    jam = true;
                    break;
                }
            }


        }

        }

        if (visited[gears-1] != 0)
        {
            //cout << "FOUND "<< endl;
            found = true;
            if (list[gears-1].first[3] == 2)
            {
                //cout << "Same direction" << endl;
                sameD = true;
            }
            else
            {
                //cout << "not same" << endl;
            }
            break;
        }


    }

    if (jam)
    {
        cout << "-1" << endl;
    }
    else
    {
        if (found)
        {
            int a = list[gears-1].second;
            int b = list[0].second;


            int gc;
            if (a > b)
            {
                gc = gcd(a, b);
            }
            else
            {
                gc = gcd(b, a);
            }

            int ansa = a/gc;
            int ansb = b/gc;

            //lowest form of b
            if (sameD)
            {
                cout << ansa << " " << ansb << endl;
            }
            else
            {
                cout << ansa << " " << ansb*-1 << endl;
            }
        }
        else
        {
           cout << "0" << endl;
        }

    }

}
