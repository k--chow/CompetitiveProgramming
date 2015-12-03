#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    string a = "12345";


    sort(begin(a), end(a));
    while(next_permutation(a.begin(), a.end()))
    {
        cout << a << endl;
    }
}
