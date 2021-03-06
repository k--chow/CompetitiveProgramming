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

string stringAddition(string a)
{

    for(int i=a.length() -1; i> -1; i--)
    {
        int j = (int)a[i] - 48;
        //cout << j << endl;
        j++;
        if (j == 10)
        {
            a[i] = '0';
            if (i== 0)
            {
                //append to string
                a = "1" + a;
            }
        }
        else
        {
            a[i] = j + '0';
            break;
        }


    }
    return a;
}

bool isPalindrome(string a)
{
    string b,c;
    if (a.length()%2 == 0)
    {
        b = a.substr(0, a.length()/2);
        c = a.substr(a.length()/2, a.length()/2);
        //cout << b << endl;
        //cout << c << endl;

    }
    else
    {
        b = a.substr(0, a.length()/2);
        c = a.substr(a.length()/2 +1, a.length()/2);

    }
    string d = reverseString(c);
    if (b == d)
    {
        //cout << "true" << endl;
        return 1;
    }

    return 0;
}

string closestPalin(string &a)
{
    if (a.length() == 1)
    {
        return a;
    }
    if (isPalindrome(a)) //check palindrome
    {
        a = stringAddition(a);
        //cout << a << endl;
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
    }
    else //reverse b is smaller than c
    {


    //even concat
    if (a.length() % 2 == 0)
    {
        string d = stringAddition(b);
        ans = d +reverseString(d);
    }
    else
    {
        string d = stringAddition(b+mid);
        string e = reverseString(d);
        e.erase(0, 1);
        ans = d + e;
    }


    }

    return ans;
}

int main()
{
    vector<string> ans;
    //int c;
    //cin >> c;
    for(int i=0; i<c; i++)
    {
        string k;
        cin >> k;
        if (k == '0') break;
        ans.push_back(closestPalin(k));

    }
    for(int i=0; i<ans.size(); i++)
    {
        cout << ans.at(i);
        if (i != ans.size()-1)
        {
            cout << endl;
        }
    }
}
