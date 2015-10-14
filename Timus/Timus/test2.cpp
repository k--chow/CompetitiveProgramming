#include <iostream>
#include <stdio.h>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> t;
    vector<int>::iterator it;
    t.push_back(1);
    t.push_back(5);
    t.push_back(3);

    int d = std::find(t.begin(), t.end(), 3) - t.begin();
    cout << d;
}
