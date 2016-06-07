#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
using namespace std;
int arr[8];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cases;
    cin >> cases;
    for(int i=0; i<cases; i++)
    {
        int n;
        cin >> n;
        string a;
        cin >> a;
        memset(arr, 0, sizeof(int)*8);
        for(int j=0; j<38; j++)
        {
            string inQ = a.substr(j, 3);
            if (inQ == "TTT")
            {
                arr[0]++;
            }
            else if (inQ == "TTH")
            {
                arr[1]++;
            }
            else if (inQ == "THT")
            {
                arr[2]++;
            }
            else if (inQ == "THH")
            {
                arr[3]++;
            }
            else if (inQ == "HTT")
            {
                arr[4]++;
            }
            else if (inQ == "HTH")
            {
                arr[5]++;
            }
            else if (inQ == "HHT")
            {
                arr[6]++;
            }
            else
            {
                arr[7]++;
            }
        }
        cout << i+1 << " " << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << " " << arr[4] << " " << arr[5] << " " << arr[6] << " " << arr[7] << endl;
    }
}
