#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <cstring>
#include <queue>
using namespace std;
//no numbers
//random character
//consecutive _
int main()
{
    string a;
    while(cin >> a)
    {
        int type = 0;
        bool conf = false;
        //check case first caps - NAH

        for(int i=0; i<a.length(); i++)
        {
            if (a[i] == '_')
            {
                if (type == 2)
                {
                    conf = true;
                    break;
                }
                else if (i==0 || i == a.length()-1)
                {
                    conf = true;
                    break;
                }
                else if (a[i-1] == '_')
                {
                    conf = true;
                    break;
                }
                else
                {
                    type = 1;//C++
                }

            }
            else if (isupper(a[i]))
            {
                if (type == 1)
                {
                    conf = true;
                    break;
                }
                else if (i == 0)
                {
                    conf = true;
                }
                else
                {
                    type = 2;//Java
                }

            }

        }

        if (conf)
        {
            cout << "Error!" << endl;
        }
        else if (type == 0)
        {
            cout << a << endl;
        }
        else
        {

            for (int i=0; i<a.length(); i++)
            {
                //replace _ i--
                if (a[i] == '_')
                {

                    char c = toupper(a[i+1]);
                    a[i] = c;
                    //cout << c << endl;
                    a.erase(i+1, 1);


                }

                //replace caps i++
                else if (isupper(a[i]))
                {
                    string b = "_";
                    b+=tolower(a[i]);
                    a.replace(i, 1, b);
                }
            }
            cout << a << endl;
        }

    }

}
