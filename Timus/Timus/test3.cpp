#include <iostream>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

class FallingSand
{
	public:
		vector<string> simulate(vector<string> board)
		{
			int n = board.size();
			int m = board[0].size();
            for (int a =0; a<m; a++) //columns left to right
            {
                int lastEmpty = n-1;
                for (int b = n-1; b>= 0; b--) //rows bottom to top
                {
                    if (board[b][a] == 'x')
                    {
                        lastEmpty = b-1;
                    }
                    else if (board[b][a] =='o')
                    {
                        swap(board[b][a], board[lastEmpty][a]);
                        lastEmpty--;
                    }
                }
            }
        }



};





