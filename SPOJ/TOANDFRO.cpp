#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> ans;
    while(1)
    {
        int columns;
        cin >> columns;
        if (columns == 0)
        {
            break;
        }
        string word;
        cin >> word;
        int rows = word.length()/columns;
        char letters[rows][columns];

        for(int row=0,index = 0; row < rows; row++)
        {
            if (row % 2 == 0) //even row
            {
                for(int j=0; j<columns; j++)//row times
                {
                    letters[row][j] = word[index+j];
                }
                index+=(2*columns)-1;
            }
            else if (row % 2 !=0)//odd row opposite
            {
                //cout << "odd" << endl;
                for(int j=0; j<columns; j++)
                {
                    letters[row][j] = word[index-j];
                }
                index+=1;
            }
            else
            {
                cout << "dafuq" << endl;
            }
        }
        string answ= "";
        for(int a=0; a<columns; a++)
        {
            for (int b = 0; b<rows; b++)
            {
                answ+= letters[b][a];
            }

        }
        ans.push_back(answ);

    }

    for(int i=0; i<ans.size(); i++)
    {
        cout << ans.at(i) << endl;
    }
}
