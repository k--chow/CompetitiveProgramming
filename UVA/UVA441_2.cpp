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
    int cases;
    bool second = false;
    while(cin >> cases)
    {
        vector<int> c;
        if (cases == 0)
        {
            break;
        }
        else if (second)
        {

            cout << endl;
        }
        for(int i=0; i<cases; i++)
        {
            int next;
            cin >> next;
            c.push_back(next);
        }
        second = true;
        //next 6 for loops
        for(int i=0; i< c.size()-5; i++)
        {
            for(int j=i+1; j < c.size()-4; j++)
            {
                for(int k =j+1; k<c.size() - 3; k++)
                {
                    for(int l =k+1; l<c.size()-2 ; l++)
                    {
                        for(int m = l+1; m< c.size()-1; m++)
                        {
                            for(int n=m+1; n<c.size(); n++)
                            {
                                cout << c[i] << " " << c[j] << " " << c[k] << " " << c[l] << " " << c[m] << " " << c[n] << endl;
                            }
                        }
                    }
                }
            }
        }


    }
}
