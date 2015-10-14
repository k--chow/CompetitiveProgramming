#include <iostream>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

class EightRooks
{
	public:
		string isCorrect(vector<string> board)
		{
            int count = 0;
            bool go = true;
            for (int r=0; r<8 && go; r++) //rows
            {
                for (int c=0; c<8 && go; c++)
                {
                    if (board[r][c] == 'R')
                    {
                        count++;
                        int counta=0;
                            int countb = 0;
                        for(int a=0; a<8 && go; a++)
                        {


                            if (board[r][a] == 'R')
                            {
                                counta++;

                            }

                            if (board[a][c] == 'R')
                            {
                                countb++;

                            }


                        }

                        if (counta == 1 && countb == 1)
                            {

                            }
                            else
                            {
                                go = false;
                            }

                }
            }
		}
		if (go && count==8)
		{
            return "Correct";
		}
		else
		{
            return "Incorrect";
		}



}
};

