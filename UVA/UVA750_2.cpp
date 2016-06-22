#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int ans[8];
int posA, posB;

bool place(int row, int column)//see if placeable
{

    for(int i=0; i<row; i++)
    {
        //make sure column's arent aligned ( rows already aren't)
        if (ans[i] == column)
        {

            return false;
        }

        //make sure diagonals aren't aligned
        if (abs(ans[i]- column) == abs(row - i))
        {
            return false;
        }
    }
    return true;
}

void recursion2(int column)//we do this
{
    if (column == 9 && ans[posB] == posA)
    {
        for(int i=1; i <9; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    for(int r=1; r<9; r++)
    {
        if (place(r, column))
        {
            ans[column] = r;
            recursion2(column+1);
        }
    }

}

void recursion3(int row)
{
    if (row == 8 && ans[posA] == posB)
    {
        for(int i=0; i<8; i++)
        {
            cout << ans[i]+1 << " ";
        }
        cout << endl;
    }

    for(int column = 0; column < 8; column++)
    {
        if (place(row, column))
        {
            ans[row] = column;
            recursion3(row+1);
        }
    }
}

void recursion(int row, int column)
{
    cout << row << " " << column << endl;
    //row = 9, met and print
    if (row == 8)
    {
        for(int i=0; i <8; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    //if 3 conditions met, row++ and add to ans
    if (place(row, column))
    {
        ans[row] = column;
        recursion(row+1, column);
    }

    //else column++

}

void recurse(int row, int column)
{
    cout << row << " " << column << endl;
    //if row == 9 break;
    if (row == 9) {

                for(int i=1; i<9; i++)
                {
                    cout << ans[i] << " ";
                }

            return;
    }
    //if conditions met, row ++, add column
    bool met = true;
    for(int r=1; r<row; r++)
    {
        //if cond met
        if (row == r || column == ans[r] || (abs(r-row) == abs(column - ans[r])))//diagonal, row or column
        {
            met = false;
            break;
        }

    }
        if (met)//row++;
        {
            ans[row] = column;
            recurse(row+1, 1);
        }
        //else if column != 8, column++;
        else if (column != 8)
        {
            recurse(row, column+1);
        }
        else
        {
            cout << "here boo" << endl;
            //backtracking needed
            return;
        }



}

int main()
{

    cin >> posA >> posB;
    posA--;
    posB--;

    //ans[posA] = posB;

    //recursion3(0);
    for(int col =0; col<8; col++)
    {
        recursion(col, 0);
    }




}
