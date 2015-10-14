#include <iostream>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;
int numbers[8] = {10, 11, 12, 13, 14, 15, 1, 0};
string letters[8] = {"A", "B", "C", "D", "E", "F", "I", "O"};
vector<string> answer;

int main()
{
    bool end = false;
    long long input;
    cin >> input;
    long long original = input;
    int size = 1;
    while (input /= 16)
    {
        size++;
    }



    for(int i=0; i<size; i++)
    {
        long long r = original % 16;
        original /= 16;
        int index = distance(numbers, find(numbers, numbers+8, r));
        if (index < 8)
        {
            answer.insert(answer.begin(), letters[index]);
        }
        else
        {
            i = size;
            end = true;
        }

    }
    if (end)
    {
        printf("%s", "Error!");
    }
    else
    {
        for(int i=0; i<size; i++)
        {
            string c = answer.at(i);
            cout << c;
        }
    }

}
