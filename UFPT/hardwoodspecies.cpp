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
#include <queue>
#include <iomanip>
#include <map>
using namespace std;

int main()
{
    int cases; cin >> cases;
    cout << fixed;
    cout << setprecision(4);
    for(int i =0; i <cases; i++)
    {
        map<string, double> mappy;
        double count = 0;
        string tree;
        getline(cin, tree);
        getline(cin,tree);
        while (tree != "")
        {
            count++;
            if (mappy.count(tree)) {
                mappy[tree]++;
            } else {
                mappy[tree] = 1;
            }
            getline(cin,tree);
        }
        for(auto& t: mappy)
        {
            cout << t.first << " " << (t.second/count)*100 << endl;
        }
        cout << endl;
    }
}

/*
1

Red Alder
Ash
Aspen
Basswood
Ash
Beech
Yellow Birch
Ash
Cherry
Cottonwood
Ash
Cypress
Red Elm
Gum
Hackberry
White Oak
Hickory
Pecan
Hard Maple
White Oak
Soft Maple
Red Oak
Red Oak
White Oak
Poplan
Sassafras
Sycamore
Black Walnut
Willow

Sycamore
Black Walnut
Willow


*/
