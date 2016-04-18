#include <algorithm>
#include <vector>
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

    for(int i=0; i<cases; i++)
    {
        int a, total;
        cin >> a >> total;

        vector<int> arr;
        for(int j=0; j<a; j++)
        {
            int element;
            cin >> element;
            if (element > 0) {
                arr.push_back(element);//element
            }
        }

        sort(arr.begin(), arr.end());

        //array is sorted as of above
        //loop through array and binary search the answer
        int ansA;
        int ansB;
        bool found = false;

        for(int j=0; j<arr.size(); j++)
        {
            int f = total/arr[j];

            if (total % arr[j] == 0)
            {

                //binary search for f
                //make sure index j isn't the same

                if (binary_search(arr.begin()+j+1, arr.end(), f))
                {
                    found = true;
                }

                if (found) //break out of loop, not found keep traversing
                {
                    ansB = f;
                    ansA = arr[j];
                    break;
                }
            }


        }

        if (found) {
            cout << ansA << " " << ansB << endl;
        }
        else
        {
            cout << "-1" << endl;
        }

    }

}
