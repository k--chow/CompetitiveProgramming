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
#include <unordered_map>
using namespace std;


int main()
{
    int ca;
    //vector<int> ans;
    cin >> ca;
    for(int i=0; i<ca; i++)
    {
        int n, f;
        cin >> n >> f;
        int stuff[f];
        for(int j=0; j<f; j++)
        {
            int a;
            cin >> a;
            stuff[j] = a;
        }
        std::sort(stuff, stuff + f);
        int sum = 0;
        int ct = 0;
        int index = f-1;
        string answ;

        while (sum < n)
        {
            if (index == -1)
            {
                answ = "impossible";
                break;
            }
            ct++;
            sum += stuff[index];
            index--;
        }
        if (answ != "impossible")
        {
            answ = to_string(ct);
        }
        cout << "Scenario #" << i+1 << ":" << endl;
        cout << answ << endl;
        cout << endl;
    }
}
