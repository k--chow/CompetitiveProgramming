#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <unordered_map>
#include <set>
#include <map>
using namespace std;

/*
Solution: Do some data parsing and save the unique names. Then map them to some number,
as if they are nodes in a graph. Make an adjacency list, then implement BFS.
*/

void bfs(vector<vector<int> > & matrix, vector<int> & visited , int start)
{

    deque<int> q;
    visited[start] = -1;


    //push_back and pop_front

    for(int i=0; i< matrix.at(start).size(); i++)
    {
            visited[matrix.at(start).at(i)] = 1;
            //cout << matrix.at(start-1).at(i);
            q.push_back(matrix.at(start).at(i));
           // cout << q.front() << endl;
    }

    //while queue isn't empty, keep going
    //all in queue right now branded as 1
    int counter = 2;
    int scounter = 0;
    int s = q.size();

    while (!q.empty())
    {
        //dequeue
        int de = q.front();
        //cout << de + 1 << endl;
        //cout << q.front() << endl;
        q.pop_front();
        scounter++;
            //if statement to check if tier/level is completed


        for(int i=0; i<matrix.at(de).size(); i++) //adj list
        {
            if (visited[matrix.at(de).at(i)] == 0) //unvisited
            {
                q.push_back(matrix.at(de).at(i));
                visited[matrix.at(de).at(i)] = counter;


            }





        }

        if (scounter == s)
            {
                //reached end of level
                counter++;
                scounter = 0;
                s = q.size();
                //cout << "NEW LEVEL" << endl;
            }

    }




}



int main()
{
    map<string, int> names1;
    set<string> names;
    vector<string> team;
    vector< vector<int> > list(300);
    vector<int> visited;
    int teams;
    cin >> teams;
    for(int i=0; i<teams; i++)
    {
        string a, b, c;
        cin >> a >> b >> c;
        names.insert(a);
        names.insert(b);
        names.insert(c);
        team.push_back(a);
        team.push_back(b);
        team.push_back(c);
    }
    set<string>::iterator it;
    int in = 0;
    for(it=names.begin(); it!=names.end(); it++)
    {
        //cout << *it << endl;
        names1[*it] = in;
        in++;
    }


    for(int i=0, j=1, k=2; i<team.size(); i+=3) //every 3 graph them
    {
        j = i+1;
        k = j+1;
        //cout << names1[team[i]] << names1[team[j]] << names1[team[k]] << endl;

        list.at(names1[team[i]]).push_back(names1[team[j]]);
        list.at(names1[team[i]]).push_back(names1[team[k]]);


        list.at(names1[team[j]]).push_back(names1[team[i]]);
        list.at(names1[team[j]]).push_back(names1[team[k]]);

        list.at(names1[team[k]]).push_back(names1[team[i]]);
        list.at(names1[team[k]]).push_back(names1[team[j]]);
    }


    for(int i=0; i<names1.size(); i++)
    {
        for(int j=0; j<list.at(i).size(); j++)
        {
            cout << list.at(i).at(j) << " ";
        }
        cout << endl;
    }

    bfs(list, visited, names1["Isenbaev"]);
    //it = names.begin();
    for(int i=0; i<visited.size(); i++)
    {

        cout << visited[i] << endl;
    }


}
