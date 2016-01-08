#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <sstream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
int p,q,r,s,t,u;
double x;
double ans;
void BS(double low, double high)
{
    x = (low+high)/2.0;
    cout << "X " << x << endl;
    double a = p*exp(-x);
    double b = q*sin(x);
    double c = r*cos(x);
    double d = s*tan(x);
    double e = t*pow(x, 2.0);
    double f = u;
    double reach = a + b + c + d + e + f;

    cout << "reach " << reach << endl;
    if ()
    {
        ans = -1;
        cout << "No Answer!" << endl;
        return;

    }
    else if (reach < 0.0001 && reach > -0.0001)
    {
        ans = x;

        cout << "Ans " << x << endl;
        return;
    }
    else if (reach < 0)
    {
        high = x;

        BS(low, high);
    }
    else
    {
        low = x;
        BS(low, high);
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


        while(cin>>p>>q>>r>>s>>t>>u)
        {

    x = 1;
    BS(0, 1);
        }


}
