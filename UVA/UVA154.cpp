
/* UVA 154
https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=90 */
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <cstring>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> answ;
    //roygb 01234
    char colortype[101][5];
    memset(colortype, '0', sizeof(colortype[0][0]) * 5 * 10);
    string s;
    int count = 0;
    int minDi;
    int ans;
    int diff;



        while (true) {
        cin >> s;
        if (s[0] == '#')
            break;
        else if (s[0] == 'e') {
            //compare differences

            ans = 0;
            diff = 0;
            minDi = 10000;
            for(int d = 0; d < count ; d++)
            {


                for(int c = 0; c < 5 ; c++)//travese across
                {

                    char ch = colortype[d][c];
                        for(int r = 0; r < count; r++)//traverse down
                        {
                            if (ch != colortype[r][c])
                            {
                                diff++;
                            }
                        }

                }


                if (diff < minDi)
                {
                    minDi = diff;
                    ans = d+1;
                }

                diff = 0;


            }

            answ.push_back(ans);
            count = 0; //reset stupid
        }
        else
        {
            //0 and then add 4 for color
            //2 and then add 4 for type
            for(int i = 0,j = 2; j<19; i+=4, j+=4)
            {
                char color = s[i];
                char type = s[j];
                //cases
                switch(color)
                {
                case 'r': colortype[count][0] = type; break;
                case 'o': colortype[count][1] = type; break;
                case 'y': colortype[count][2] = type; break;
                case 'g': colortype[count][3] = type; break;
                case 'b': colortype[count][4] = type; break;

                }
            }
            //cout << count;
            count++;
        }


        }
    //vector<int>::iterator a;
    for(int a = 0; a<answ.size(); a++)
    {

        cout << answ.at(a) << endl;
    }

    return 0;

}
