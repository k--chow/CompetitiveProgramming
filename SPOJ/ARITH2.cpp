#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cases;
    cin >> cases;
    for(int i=0; i <cases; i ++)
    {
        long long int ans;
        cin >> ans;
        while (1)
        {
            long long int a;
            char b;
            cin >> b;
            if (b == '='){
                break;
            }
            else
            {
                cin >> a;
                if (b == '+')
                {
                    ans+=a;
                }
                else if (b == '-')
                {
                    ans-=a;
                }
                else if (b=='*')
                {
                    ans*=a;
                }
                else
                {
                    ans/=a;
                }
            }
        }
        cout << ans << endl;
    }

}
