#include <iostream>
#include <stdio.h>
#include <vector>
#include <iomanip>
using namespace std;
int main()
{
    int b = 5;
    vector<int> a;
    for (int i=0; i<b; i++)
    {
        a.push_back(i);
        printf("%i ", a.at(i));
    }
}
