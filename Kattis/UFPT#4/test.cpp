#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unordered_map>
#include <map>
#include <sstream>

using namespace std;

int main()
{
    vector<string> hello;
    hello.push_back("abc");
    hello.push_back("ab");
    hello.push_back("a");
    sort(hello.begin(), hello.end());
    for(int i=0; i<hello.size(); i++)
    {
        cout << hello[i] << endl;
    }
}
