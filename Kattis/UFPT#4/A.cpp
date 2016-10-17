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
#include <map>
#include <sstream>

using namespace std;

void split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

int main()
{
    int cases; cin >> cases;
    for(int i=0; i<cases; i++)
    {
        string p; cin >> p;
        int s; cin >> s;
        string line;
        getline(cin, line);
        getline(cin, line);
        line.erase(remove(line.begin(),line.end(), '['), line.end());
        line.erase(remove(line.begin(),line.end(), ']'), line.end());
        vector<string> arr = split(line, ',');
        int leftIndex = 0, rightIndex = arr.size()-1;
        int r = 0;
        bool error = false;
        for(char c: p)
        {
            if (c == 'R')
            {
                r++;
            } else {
                //drop
                if (leftIndex > rightIndex) {
                    error = true;
                    break;
                }
                else if (r % 2 == 0) {//same original order
                    leftIndex++;
                } else {
                    rightIndex--;
                }
                //check empty error
            }
        }
        if (error)
        {
            cout << "error" << endl;
        }
        else if (r % 2 == 0)
        {
            cout << "[";
            while(leftIndex <= rightIndex)
            {
                cout << arr[leftIndex++];
                if (leftIndex-1 != rightIndex) {
                    cout << ",";
                }
            }
            cout << "]" << endl;
        } else {
            cout << "[";
            while (rightIndex >= leftIndex)
            {
                cout << arr[rightIndex--];
                if (leftIndex != rightIndex+1) {
                    cout << ",";
                }
            }
            cout << "]" << endl;
        }

    }
}
/*
2
RDD
4
[1,2,3,4]
RDD
4
[1,2,3,4]*/
