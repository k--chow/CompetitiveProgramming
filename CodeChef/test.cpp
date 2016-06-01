#include <iostream>
using namespace std;
int licznik = 0;
int liczba = 0;
int main()
{
    int T, N, A[10^9], B[10^9];
    cin>>T;
    //while(T--)
    //{
        cin>>N;
        for (int i = 0; i<N; i++)
        {
            cin>>A[i];
        }
        for (int c = 0; c<N; c++)
        {
            cin>>B[c];
        }
        if (A[licznik-1] >= B[licznik])
        {
            liczba++;
        }
        cout<<liczba;
    //}
    return 0;
}
