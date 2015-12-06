//input ends with 0
//line = k, k elements of S
//k is 7 to 12
//clearly just combinations
//print out in ascending order

#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
//max is 12 nCr 6 = 924

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k = -1;
    vector<int> abe;
    //parse
    int i;
    vector<string> ans;
    while (true)
    {
        cin >> k;
        //cout << "k: " << k << endl;
        abe.clear();
        if (k == 0)
        {
            //cout << "Broken" << endl;
            break;
        }
        else
        {
            for (int j = 0; j < k; j++)
            {
                cin >> i;
                abe.push_back(i);
            }
            //cout << endl;
            for(int a=0; a<k-5; a++)
            {

                for(int b=a+1; b<k-4; b++)
                {
                    for (int c = b+1; c<k-3; c++)
                    {
                        for(int d = c+1; d <k-2; d++)
                        {
                            for (int e = d+1; e<k-1; e++)
                            {
                                for (int f = e+1; f<k; f++)
                                {
                                    cout <<  abe.at(a) << " " << abe.at(b) << " " << abe.at(c) << " " << abe.at(d) << " " << abe.at(e) << " " << abe.at(f) <<endl << std::flush();

                                }

                            }
                        }
                    }
                 }
             }
        } //end of else





    } //end of while
    std::flush();

    //cout << "?";
    //next_permutation
    return 0;

}

