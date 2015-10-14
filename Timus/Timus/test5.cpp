#include <iostream>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{
    int hours = 0;
    int totalComputers;
    int cables;
    scanf("%i %i", &totalComputers, &cables);
    int PC = 1;
    while (PC < totalComputers)
    {

        if (PC <= cables)
        {
            PC+=PC;
        }
        else
        {
            PC+=cables;
        }

        hours++;
    }
    printf("%i", hours);

}
