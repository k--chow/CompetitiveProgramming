#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <cstring>
#include <queue>
using namespace std;

int main()
{
    int cases, N, K;
    cin >> cases;
    //cout << cases << endl;
    for(int i=0; i<cases; i++)
    {

        cin >> N >> K;
        cout << N << " a " << K << endl;
        vector<int> kids;
        for(int j=0; j<N; j++)
        {
            int kid;
            cin >> kid;
            kids.push_back(kid);
        }
        sort(kids.begin(), kids.end());//not working?

        int minDiff = 2000000000;

        for(int j=K-1; j<N; j++)
        {
            //cout << "hi" << endl;
            int diff = kids[j] - kids[j-K+1];
            //cout << diff << endl;
            if (diff <= minDiff)//diff is >= mindDiff
            {
                minDiff = diff;
            }
        }

        cout << minDiff << endl;
    }
}

//why the fuck isn't this working? No fucking idea. The solution is correct, but something is wrong with the fucking input.


