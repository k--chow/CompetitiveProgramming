#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <unordered_map>
using namespace std;

unordered_map<long, int> save;

void happy(long long &ans)
{
    //break into chars
    save[ans] = 1;
    string a = to_string(ans);
    ans = 0;
    for(int i=0; i<a.length(); i++)
    {
        ans+=(a[i] -'0') *(a[i]-'0');
    }
    //cout << ans << endl;
    //get ans, save

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long ans;
    cin >> ans;
    long long cnt = 0;
    while (1)
    {
        //cout << "ANS: " << ans << endl;
        //check if number is already in map
        if (save[ans] == 1){
            //cout << save[ans] << endl;
            cnt = -1;
            break;
        }

        //if not, use happy method
        else
        {
            //cout << "hi" <<endl;
            happy(ans);
            cnt++;
        }
        //if ans is 1, break
        if (ans == 1) break;
    }
    cout << cnt << endl;

}
