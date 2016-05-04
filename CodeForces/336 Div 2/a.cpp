#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string pass1;
    int pass;
    int top;
    int passe[100];
    int cost[100];
    int totalTime = 0;
    int currentFloor;
    cin >> pass1;
    pass = atoi(pass1.c_str());
    cin >> pass1;
    top = atoi(pass1.c_str());
    currentFloor = top;
    for(int i=0; i< pass; i++)
    {
        cin >> pass1;
        passe[i] = atoi(pass1.c_str());
        //cout << passe[i] << endl;;
        cin >> pass1;
        cost[i] = atoi(pass1.c_str());
        //cout << cost[i] << endl;;
    }
    int b = pass-1;
    //cout << "B: " << b << endl;
    while (currentFloor > 0)
    {
        //cout << "current floor: " << currentFloor << endl;
        //cout << "greater than 0" << endl;
        int transCost = currentFloor - passe[b];
        totalTime += transCost;
        //cout << "TT" << totalTime << endl;
        int tempCost = cost[b] - transCost;
        if (tempCost > 0)
        {
        totalTime += cost[b] - transCost;
        }
        //cout << "totaltime " << totalTime << endl;
        //minus from costs

        //cout << "tempCost" << tempCost << endl;
        for(int i=b; i>-1; i--)
        {
            //cout << "minusing cost" << endl;
            cost[i]-= currentFloor - passe[b];//cost of transport
            //cout << "cost of transport" << currentFloor - passe[b] << endl;
            if (tempCost > 0 && i != b) cost[i]-= tempCost;  //cost of waiting minus from all
            //cout << "passgener" << passe[i] << " cost " << cost[i] << endl;

        }


        currentFloor = passe[b];
        b--;
        if (b == -1)
        {
            totalTime+= currentFloor;
            //cout << "loop broken";
            break;
        }
    }
    cout << totalTime << endl;

}

