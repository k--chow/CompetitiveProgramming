//sort

//new array of pairs of distances (distance, index) index = +1

//sort it

//get smallest element, erase index

//

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
    cin >> cases;
    for(int i=0; i<cases; i++)
    {
        int stalls, cows;
        cin >> stalls >> cows;
        vector<int> stallsArray;
        vector< pair<int, int> > distArray;
        for(int j=0; j<stalls; j++)
        {
            int k;
            cin >> k;
            stallsArray.push_back(k);
        }

        std::sort(stallsArray.begin(), stallsArray.end());
        for(int j=1; j<stalls; j++)
        {
            distArray.push_back(make_pair(j, stallsArray[j]-stallsArray[j-1]));
            cout << distArray[j-1].first << " " << distArray[j-1].second << endl;
        }


        /*
        //vector removal method
        stallsArray.erase(remove(stallsArray.begin(), stallsArray.end(), stallsArray[4]), stallsArray.end());
        cout << stallsArray[stallsArray.size()-2] << endl;
        cout << stallsArray[stallsArray.size()-1] << endl;*/

    }
}

