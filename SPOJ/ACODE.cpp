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
    vector<long long> ans;
    while (1)
    {
        cin >> i;
        if (i == "0")
        {
            break;
        }

    vector<long long> arr;
    arr.push_back(0);
    arr.push_back(1);
    //100 fibonacci

    for(int t=1; t<i.length()+1; t++)//each substring
    {
        string c = i.substr(0, t);
        //cout << c << endl;
        int total = 0;
        //int a = c.length()-1;
        for(int j=t-2; j<c.length()-1; j++)//each pair
        {
            //check if pair is < 27
            string ch = i.substr(j, 2);
            int check = atoi(i.substr(j, 2).c_str());
            //cout << "check " << check << endl;
            //total = j;
            if (check > 26)
            {
                total--;
            }
            if (ch == "00")
            {
                //make it all zero
            }

            if (ch[0] == '0' || ch[1] == '0')
            {
                //subtract from previous
                arr.at(t-1)--;
            }



        }
        total+= arr.at(t) + arr.at(t-1);
        arr.push_back(total);

    }
        ans.push_back(arr.back());
    }
    for(int t=0; t<ans.size(); t++)
    {
        cout << ans.at(t) << endl;
    }





}
