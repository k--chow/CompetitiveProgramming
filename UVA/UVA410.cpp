#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <sstream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

//no chamber can be empty
//10 stars in 5 chambers

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int chamber, section;
    int c=0;
    while (cin>>chamber>>section)
    {
        c++;
        vector<int> mass2;
        int masse;
        double avg = 0;
        for(int i= 0; i<section; i++)
        {
            cin >> masse;
            mass2.push_back(masse);
            avg+=masse;
        }
        avg/=section;
        sort(mass2.begin(), mass2.end());
        while(mass2.size() < 2*chamber)
        {
            mass2.insert(mass2.begin(), 0);
        }
        cout << "Set #" << c << endl;
        for(int i=0; i<chamber; i++)
        {

            cout << " " << i << ": ";
            //output i and 2chamber - i if aren't zero
            if (mass2.at(i) != 0)
            {
                cout << mass2.at(i) << " ";
            }
            if (mass2.at(2*chamber -(i+1)) != 0)
            {
                cout << mass2.at(2*chamber -(i+1));
            }
            cout << endl;


        }
            cout << "IMBALANCE = " << avg << endl;


    }
}
