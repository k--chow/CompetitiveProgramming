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


int main() {
    int cases;
    cin >> cases;
    int chambers;
    cin >> chambers;
    int capacity[chambers][chambers];


    for (int i=0; i<chambers;i++)
    {
        for(int j=0; j<chambers; j++)
        {
            capacity[i][j] = -1;
        }

    }
    //set up matrix
    for (int i=0; i<chambers-1;i++)
    {
        int paths;
        cin >> paths;
        for(int j=0; j<paths; j++)
        {
            int neighbor;
            cin >> neighbor;
            capacity[i][neighbor-1] = 100000;
            if (neighbor == chambers)
            {
                capacity[i][chambers-1] = 1;
            }
        }

    }
    //source +1 all 1
    for(int i=0; i<chambers;i++)
    {
        if (capacity[0][i] != -1)
        {
            capacity[0][i] = 1;
        }
    }

    //sink -1 all 1
    /*
    for(int i=0; i<chambers; i++)
    {
        if (capacity[])
    }
    */

    for (int i=0; i<chambers;i++)
    {
        for(int j=0; j<chambers; j++)
        {
            cout << capacity[i][j] << " ";
        }
        cout << endl;

    }
}
