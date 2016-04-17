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
#include <stack>
using namespace std;

int main()
{
    int cases;
    cin >> cases;
    for (int i=0; i<cases; i++)
    {
        int length;
        string s;
        cin >> length >> s;
        int c = 0;
        for(int j=0; j<length; j++)
        {
            if (s[j] == '.') {
                cout << "hi" << endl;
            }
        }
    }
}
