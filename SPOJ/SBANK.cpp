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
#include <map>
using namespace std;

bool weird_sort(string a, string b)//1 means a > b, 0
{
    stringstream one(a);
    stringstream two(b);
    vector<int> tokensA;
    vector<int> tokensB;
    string three;
    while (one >>three)
        tokensA.push_back(atoi(three.c_str()));
    while (two >> three)
        tokensB.push_back(atoi(three.c_str()));
    cout << tokensA[5] << endl;
    for(int i=0; i<tokensA.size(); i++)
    {
        if (tokensA[i] != tokensB[i])
        {
            return tokensA[i] < tokensB[i];
        }
    }
    return 1;
}


int main()
{
    int cases;
    cin >> cases;
    for(int i=0; i<cases; i++)
    {

        map<string, int> swag;
        map<string, int>::iterator it;
        int accs;
        cin >> accs;
        for(int j=0; j<accs; j++)
        {
            string accNum1, accNum2, accNum3, accNum4, accNum5, accNum6;
            cin >> accNum1;
            accNum1 += " ";
            cin >> accNum2;
            accNum1 += accNum2 + " ";
            cin >> accNum3;
            accNum1 +=accNum3 + " ";
            cin >> accNum4;
            accNum1 += accNum4 + " ";
            cin >> accNum5;
            accNum1 += accNum5 + " ";
            cin >> accNum6;
            accNum1 += accNum6;
            //accNum += " ";

            it = swag.find(accNum1);
            if (it==swag.end())
            {
                swag[accNum1] = 1;
            }
            else
            {
                swag[accNum1]++;
            }
        }
        //sort a hash set
        for(it = swag.begin(); it != swag.end(); it++)
        {
            cout << it->first << " " << it->second << endl;
        }
        cout << endl;
    }


}
