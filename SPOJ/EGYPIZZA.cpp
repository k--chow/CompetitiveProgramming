#include <string>
#include <iostream>
#include <math.h>
#include <stack>
using namespace std;

int main()//use set
{
    int cases;
    cin >> cases;
    //set<string> setty;
    int a1=0, a2=0, a3=0;
    //map<string>::iterator it;
    int cnt=0;
    for(int i=0; i<cases; i++)
    {
        string p;
        cin >> p;
        if (p == "1/2")
        {
            //it = setty.find("1/2");

                a2++;

                //cout << "AYY" << endl;

        }
        else if (p == "3/4")
        {

                a3++;

                //cout << "AYY" << endl;

        }
        else //1/4
        {

                a1++;

        }

    }
    //cout << cnt << endl;
    cnt = a3;
    //cout << cnt << endl;
    cnt += a2/2;
    //cout << cnt << endl;
    int halves = a2 % 2;
    if (halves > 0)
    {
        cnt++;
        a1-=2;
    }
    //cout << cnt << endl;
    a1 = a1 - a3;


    //no quarters
    if (a1 > 0)
    {
        //3/4 and 1/2's
        //there can only be one half
        cnt+= (a1/4);
        if (a1 % 4 != 0)
        {
        cnt++;
        }

    }


    cout << cnt+1 << endl;

}
