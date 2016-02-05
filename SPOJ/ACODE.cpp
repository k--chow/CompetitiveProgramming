#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main()
{
    string i;
    cin >> i;
    vector<long long> arr;
    arr.push_back(1);
    arr.push_back(1);
    //100 fibonacci
    for(int t=0; t<30; t++)
    {
        arr.push_back(arr.at(t) + arr.at(t+1));
    }/*
    for(int t=1; t<i.length()+1; t++)//each substring
    {
        string c = i.substr(0, t);
        cout << c << endl;
        int total = arr.back();
        int a = c.length()-1;
        for(int j=0; j<c.length()-1; j++)//each pair
        {
            //check if pair is < 27
            string ch = i.substr(j, 2);
            int check = atoi(i.substr(j, 2).c_str());
            cout << "check " << check << endl;
            //total = j;
            if (check > 26)
            {
                a--;
            }


        }
        total+=a;
        arr.push_back(total);
        cout << "back " << arr.back() << endl;
    }


    cout << arr.back() << endl;*/
    for(int t=0; t<arr.size(); t++)
    {
        cout << arr.at(t) << endl;
    }
}
