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
#include <iomanip>
using namespace std;

typedef pair<pair<int, int>, int> p;
typedef vector<int> vi;
typedef vector<vi> vii;

#define PI 3.14159265

int main()
{
    while(1)
    {
        int trucks;
        cin >> trucks;
        if (trucks == 0) break;
        vector<int> trucksN;
        for(int i=0; i<trucks; i++)
        {
            int truckNo;
            cin >> truckNo;
            trucksN.push_back(truckNo);
        }

        stack<int> sideStreet;
        sideStreet.push(1002);
        int i=0;
        int current = trucksN[i];
        int needed = 1;
        bool yes = true;
        while (1)
        {
            if (needed == trucks+1) break; //finished

            if (current != needed)//current isn't the needed one
            {
                //check the stack
                //in stack, pop, don't increment i but update needed
                if (sideStreet.top() == needed)
                {
                    sideStreet.pop();
                    needed++;
                }
                //not in stack, push current to stack, increment i and update current
                //check if current > stack top, then break
                else
                {
                    if (current>sideStreet.top())
                    {
                        yes = false;
                        break;
                    }
                    else
                    {
                        sideStreet.push(current);
                        i++;
                        current = trucksN[i];
                    }
                }
            }
            else //current is the needed one, move on
            {
                //increment i, update current and needed
                i++;
                current = trucksN[i];
                needed++;

            }
        }

        if (yes) cout << "yes" << endl;
        if (!yes) cout << "no" << endl;
    }
}
