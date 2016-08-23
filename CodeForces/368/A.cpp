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
  std::ios::sync_with_stdio(false);
  cin.tie();
    int a, b; cin >> a >> b;
    bool color = false;
    for(int i=0; i< a*b; i++)
    {
        char n; cin >> n;
        if (n == 'C' || n == 'M' || n == 'Y') color = true;
    }
    if (color)
    {
        cout << "#Color" <<endl;
    } else {
        cout << "#Black&White" << endl;
    }

}
