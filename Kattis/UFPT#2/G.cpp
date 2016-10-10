#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unordered_map>
using namespace std;

int answ = 2147483647;
string ans = "";

string shiftString(string s, int i)
{
    if (s[i] == '*'){
        s[i] = '.';
    }
    else {
        s[i] = '*';
    }

    if ((i-3) >= 0) {
        if (s[i-3] == '*') {
            s[i-3] = '.';
        } else {
            s[i-3] = '*';
        }
    }
    if ((i+3) < 9) {
        if (s[i+3] == '*') {
            s[i+3] = '.';
        } else {
            s[i+3] = '*';
        }
    }
    if (i != 0 && i != 3 && i != 6)
    {
        if (s[i-1] == '*') {
            s[i-1] = '.';
        } else {
            s[i-1] = '*';
        }
    }
    if (i != 2 && i != 5 && i != 8)
    {
        if (s[i+1] == '*') {
            s[i+1] = '.';
        } else {
            s[i+1] = '*';
        }
    }
    return s;
}
void backtrack(string current, int c, unordered_map<string, bool>& exist)
{
    //cout << "current: " << current << endl;
    //check if ans
    if (current == ans) {
        cout << "yes" << endl;
        if ( c < answ) {
            answ = c;
        }
        return;
    }
    //check if inside, break if so
    if (exist.count(current)) {
        return;
    }
    //otherwise store current
    exist[current] = true;

    //for loop  get it
    for(int i=0; i<9; i++)
    {
        //string temp = current;
        string temp = shiftString(current, i);
        backtrack(temp, c+1, exist);
    }
}

int main()
{
    int cases; cin >> cases;
    for(int i=0; i<cases; i++)
    {
        answ = 2147483647;
        ans = "";
        for(int j=0; j<9; j++)
        {
            char c; cin >> c;
            ans += c;
        }
        unordered_map<string, bool> exist;
        //exist[ans] = true;
        string current = ".........";
        //exist[current] = true;
        //cout << "ans: " << ans << endl;
        backtrack(current, 0, exist);
        cout << answ << endl;
        //cout << "ans: " << ans << endl;
    }
}
