#include <string>
#include <iostream>
using namespace std;

int main()
{

    int d;
    cin >> d;
    int n[d];
    for(int i=0;i<d;i++)
    {
        int a,b,w;
        cin >> a >> b;
        if (a > 9) a %=10;
        int c;
        (b%4 == 0 && b != 0)? c = 4 :c = b%4;
        switch (c)
        {
            case 0:
            w = 1;
            break;
            case 1:
            w = a;
            break;
            case 2:
            w = (a*a)%10;
            break;
            case 3:
            w = (a*a*a)%10;
            break;
            case 4:
            w = (a*a*a*a)%10;
        }
        n[i] = w;
    }
    for(int i=0; i<d; i++)
    {cout << n[i] << endl;}
}
