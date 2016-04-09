
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
using namespace std;

int main()
{
    vector<int> operations; //1 add 2 sub 3 mult 4 div
    int ops;
    cin >> ops;
    for(int i=0; i<ops; i++)
    {
       string op;
       int rand, ope;
       cin >> op >> rand;
       if (op == "ADD")
       {

           ope = 1;
       }
       else if (op == "SUBTRACT")
       {
           ope = 2;
       }
       else if (op == "MULTIPLY")
       {
           ope = 3;
       }
       else
       {
           ope = 4;
       }
       operations.push_back(ope);
       operations.push_back(rand);

    }
    //test on 100 ints
    int counter = 0;
    for(int i=1; i<101; i++)
    {
        long temp = i;
        bool end = false;
            for(int j=0; j<2*ops; j+=2)
            {

                if (operations[j] == 1)
                {
                    temp+= operations[j+1];
                }
                else if (operations[j] == 2)
                {
                    temp-= operations[j+1];
                    if (temp < 0)
                    {
                        end = true;
                        break;
                    }
                }
                else if (operations[j] == 3)
                {

                    temp*=operations[j+1];

                }
                else
                {
                    if (temp % operations[j+1] != 0)
                    {
                        end = true;
                        break;
                    }
                    temp /=operations[j+1];

                }

            }
            //cout << temp << endl;
            //end of for loop
            if (end) counter++;

        }
        cout << counter << endl;
}
