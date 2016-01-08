#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <sstream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
#define int64 long long
string ans = "";
void BS(int64 leftNum, int64 leftDen, int64 rightNum, int64 rightDen, int64 currentNum, int64 currentDen, int64 targetNum, int64 targetDen)
{
    double current = (double)currentNum/currentDen;
    double target = (double)targetNum/targetDen;
    if (target < current) //smaller
    {
        ans+="L";
        BS(leftNum, leftDen, currentNum, currentDen, (currentNum+leftNum), (currentDen + leftDen), targetNum, targetDen);
    }
    else if (target > current)
    {
        ans+="R";
        BS(currentNum, currentDen, rightNum, rightDen, (currentNum+rightNum), (currentDen + rightDen), targetNum, targetDen);
    }
    else
    {
        if (((double)targetNum/targetDen) == 1.0)
        {
            ans = "I";
        }
        return;
    }
}
int main()
{
    int a,b;
    cin >> a >> b;
    vector<string> answers;
    while (a != 1 && b != 1)
    {
        ans = "";
        BS(0, 1, 1, 0, 1, 1, a, b);
        answers.push_back(ans);
        cin >> a >> b;
    }
    for(int i=0; i <answers.size(); i++)
    {
        cout << answers.at(i) << endl;
    }
    return 0;
}
