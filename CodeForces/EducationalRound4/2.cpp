#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
using namespace std;
int main()
{
        vector<int> ans;
        ans.push_back(5);
        ans.push_back(4);
        ans.push_back(3);
        vector<int>::iterator v;
        sort(ans.begin(), ans.end());
        v = lower_bound(ans.begin(), ans.end(), 5);
        cout << ans.end() - v - 1;
}
