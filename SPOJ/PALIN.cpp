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

bool stringCompare(string a, string b) //true is a > b
{
    for(int i=0; i<a.length(); i++)
    {
        if (b[i] > a[i])
        {
            return false;
        }
    }
    return true;
}


string reverseString(string a)
{
    string newString = "";
    for(int i=a.length()-1; i > -1; i--)
    {
        newString+=a[i];
    }
    return newString;
}

string stringAddition(string &a)
{

    for(int i=a.length -1; i> -1; i++)
    {
        a[i] += 1 - 48;
        if (a[i] == ':' || a[i] == ';') && i != 0)
        {
            a[i-1]+=1;
        }
    }
}

string closestPalin(string a)
{
    if (a.length() == 1)
    {
        return a;
    }
    //length is even
    string b, c, ans, mid="";
    if (a.length() % 2 == 0)
    {
        b = a.substr(0, a.length()/2);
        c = a.substr(a.length()/2, a.length()/2);
    }
    else
    {
        b = a.substr(0, a.length()/2);
        c = a.substr((a.length()/2) +1, a.length()/2);
        mid = a[a.length()/2];
    }
    string rev = reverseString(b);
    //cout << rev;

    if (stringCompare(rev, c)) //reverse b is greater than c
    {
        ans = b + mid + rev;
        //cout << b;
        //cout << mid;
        //cout << rev;
    }
    else //reverse b is smaller than c
    {
    //add one starting from mid

    //even concat

    //odd +1 == -1

    }

    return ans;
}




int main()
{
    string a = "807";
    string b = "8007";
    a[1] += a[1] - 48 + 11;
    //cout << closestPalin(b) << endl;
    cout << a[1]<< endl;
}
