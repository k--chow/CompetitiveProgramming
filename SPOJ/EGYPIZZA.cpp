#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <set>
#include <unordered_map>
using namespace std;

int main()//use set
{
    // 1/2 - check if stack has 1/2 and pop, if not, ++ and add 1/2 to stack
    // 1/4 - check if stack has 1/4 and pop, if not, ++, and add 3/4 to stack
    // 3/4 - check if stack has 3/4 and pop, if not, ++, and add 1/4 to stack
    int cases;
    cin >> cases;
    //set<string> setty;
    unordered_map<string, int> setty;
    //map<string>::iterator it;
    int cnt = 1;
    for(int i=0; i<cases; i++)
    {
        string p;
        cin >> p;
        if (p == "1/2")
        {
            //it = setty.find("1/2");
            if (setty["1/2"] != 0)
            {
                setty["1/2"]--;
            }
            else
            {
                setty["1/2"]++;
                cnt++;
                //cout << "AYY" << endl;
            }
        }
        else if (p == "3/4")
        {

            if (setty["3/4"] != 0)
            {
                setty["3/4"]--;
            }
            else
            {
                setty["1/4"]++;
                cnt++;
                //cout << "AYY" << endl;
            }
        }
        else //1/4
        {

            if (setty["1/4"] != 0)
            {
                setty["1/4"]--;
            }
            else
            {
                setty["3/4"]++;
                cnt++;
            }
        }

    }
    cout << cnt << endl;

}
