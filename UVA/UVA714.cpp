#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <sstream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
int m, k, a[510], macx=0;;
void run()
{
    for(int i=1; i<macx; i++)//over entirety
    {
        int currentBook = 0;
        for(int j=1; j<k+1; j++)//over each scribe
        {
            int currentPages = 0;

            for(int p=currentBook; p<m; p++)//over each book
            {
                if (currentPages + a[p] <= i)
                {
                    currentPages+=a[p];
                    currentBook = p+1;
                }
                else
                {
                currentBook = p;
                break;
                }
            }
        }
    }
}
//own solution

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin >> m;
        cin >> k;
        for(int j=0; j< m; j++)
        {
            cin >> a[j];
            macx+=a[j];
        }
        //run algorithm
    }

}
