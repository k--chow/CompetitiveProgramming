
//get all CAPS based on 3 capital letters
//save all the categories to the prefix
//save to hashmap, if multiple use linkedlist
//also save each to array, if duplicated, dont add
//run through array of prefixes, run through each of its categories through linked list
//match it to new file - save each link to new hashmap of prefixes
//run for loop - else if for each prefix - output its linkedlist of crap

//ignore all spaces parse
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
    ifstream test;
    string fileName = "file1.txt";
    test.open(fileName.c_str());
    string line;
    while(std::getline(test, line))
    {
        cout << "hi" << endl;
    }
    //cout << "hi" << endl;
    return 0;
}

