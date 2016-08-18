#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <unordered_map>
#include <map>
#include <queue>
#include <iomanip>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie();
    double cases, AB, AC, AD, BC, BD, CD, ans;
    cin >> cases;
    for(int i=0; i<cases; i++)
    {
        ans = 0.0;
        cin >> AB >> AC >> AD >> BC >> BD >> CD;
        AB = pow(AB, 2);
        AC = pow(AC, 2);
        AD = pow(AD, 2);
        BC = pow(BC, 2);
        BD = pow(BD, 2);
        CD = pow(CD, 2);
        double ux = CD + BC - BD;
        double vx = BC + AC - AB;
        double wx = AC + CD - AD;
        double ux2 = pow(CD + BC - BD, 2);
        double vx2 = pow(BC + AC - AB, 2);
        double wx2 = pow(AC + CD - AD, 2);
        ans = (4.0000*AC*CD*BC) - (AC*ux2) - (CD*vx2) - (BC*wx2) + (ux*vx*wx);
        ans = sqrt(ans);
        ans = ans/12.0000;
        cout << setprecision(4) << fixed << ans << endl;
    }
}
