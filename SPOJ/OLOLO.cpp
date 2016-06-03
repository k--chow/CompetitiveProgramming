#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <unordered_map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    unordered_map<int,  setty;
    //setty.insert(5);
    unordered_map::iterator it;
    for(int i=0; i<n; i++)
    {
        int n1;
        cin >> n1;
        //if found, erase
        it = setty.find(n1);
        if (it != setty.end())
        {
            setty.erase(it);
        }
        //if not, insert
        else
        {
            setty.insert(n1);
        }

    }

    //print out only element in set
    for(it = setty.begin(); it!=setty.end(); it++)
    {
        cout << *it << endl;
    }
}
