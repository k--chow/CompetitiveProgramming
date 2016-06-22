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
    int given;
    while (cin >> given)
    {
        if (given == 0) break;//only use each number once
        string a = "01234";

        int a1 = atoi(a.c_str());
        while (1) {
        if (a1*given <= 98765/N )
        {
            //if no digits are found
            cout << a1*given << " / " << a1 << endl;
        }
        else
        {
            break;
        }
        next_permutation(a.begin(), a.end());
        }
    }

//01234 / 56789
}
