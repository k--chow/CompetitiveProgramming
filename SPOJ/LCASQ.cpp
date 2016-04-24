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

//segment tree solely for Range Minimum Queries (RMQ) of levels
class SegmentTree {

    public:
    vector<int> levels; //backing array
    vector<int> left; //store left nodes array
    vector<int> right; //store right nodes array
    vector<int> tree; //stores index of minimum level
    int s; //size;
    int m; //min

    SegmentTree(vector<int> level)
    {
        this->m = 1000000;
        this->levels = level;
        this->s = level.size();
        for(int i=0; i<s*4; i++)
        {
            tree.push_back(0);
            left.push_back(0);
            right.push_back(0);
        }
        //now build
        build(0, 0, s-1);
    }

    void build(int tree_index, int start_index, int end_index) //build the tree
    {
        left[tree_index] = start_index;
        right[tree_index] = end_index;
        //if start = end, set that tree_index to itself, then break
        if (start_index == end_index)
        {
            this->tree[tree_index] = start_index;
            return;
        }
        //find smallest level in between the 2 indexes
        int smallest = 1000000;
        int index;
        for(int i=start_index; i<end_index+1; i++)
        {
            if (this->levels[i] < smallest)
            {
                index = i;
                smallest = this->levels[i];
            }
        }

        //set tree[tree_index] to that value
        tree[tree_index] = index;
        //cout << tree[tree_index] << endl;
        //build left node
        //cout << "Building left " << start_index << " " << (start_index + end_index)/2 << endl;
        build((2*tree_index) + 1, start_index, (start_index + end_index)/2);

        //cout << "Building right " << ((start_index + end_index)/2)+1 << " " << end_index << endl;
        //build right node
        build((2*tree_index) + 2, ((start_index + end_index)/2)+1, end_index);
    }

    //query the segment/fenwick tree sum
    //solutions - save pairs of the index, use left/right for determining
    void c_min_query(int i, int j, int index) // add to a running min
    {

    	if (index == 0 && this->m != 1000000)//reset min from other queries
    	{
    	    //cout << "reset" << endl;
    		this->m = 1000000;
    	}
        //use range and check
        //orange - parts of it in it but parts of it not - continue on
        //traverse again

        //green - all a part of it, math.min this on this
        if (left[index] >= i && right[index] <= j)
        {
            if (this->m == 1000000)
            {
                this->m = tree[index];//set things to the index, not the actual level
            }
            else
            {
                if (levels[tree[index]] < levels[this->m])
                {
                    this->m = index;
                }
            }
            //cout << "Index: " << tree[index] << " Level " << levels[tree[index]] << endl;


            return;
        }
        //red all are NOT a part of this, return 0 on this
        else if ((left[index] > j) || (right[index] < i))
        {

            return;
        }
        else //orange node
        {

            c_min_query(i, j, (2 * index) + 1); //left
            c_min_query(i, j, (2 * index) + 2); //right
        }

    }



};


//write LCA function to return euler[RMQ(first_occurence[i], first_occurence[j], level vector, first_occurence vector)]
bool finish = false; //finish is used to find out when to end the recursive statements



void DFS (vector<int> & euler, vector<int> & level, vector< vector<int> > graph,  int current, int previous, int n, int currentLevel, vector<int> & first_occurence)
{
    //get all the neighbors
    for(int i=0; i<graph[current].size(); i++)
    {
        //make sure its not parent(previous)
        if (graph[current][i] != previous)
        {

            euler.push_back(graph[current][i]);
            if (first_occurence[graph[current][i]] == -1)
            {
                first_occurence[graph[current][i]] = euler.size()-1 ; // set first_occurence
            }
            //cout << "LEVEL: " << currentLevel+1 << endl;
            level.push_back(currentLevel + 1);


            //cout << "ORIGINAL ADD " << graph[current][i] << endl;
            if (graph[current][i] == n-1) //find a way to break all recursive statements after this break
            {
                //cout << "BREAK" << endl;
                finish = true;
                return;
            }
            DFS(euler, level, graph, graph[current][i], current, n, currentLevel+1, first_occurence);

            if (!finish)
            {
                //cout << "ADDED " << current << endl;
                euler.push_back(current); //come back, but not if its the end
                //cout << "LEVELBACK: " << currentLevel << endl;
                level.push_back(currentLevel);
                //cout << current << " " << previous << endl;
            }


        }

    }
    //go to the first one

}

int main()
{
    int n;
    cin >> n;
    vector< vector<int> > graph(n); //safe the graph
    for(int i = 0; i<n; i++)//store the graph
    {
        int children;
        cin >> children;
        for(int j=0; j<children; j++)
        {
            int child;
            cin >> child;
            graph[i].push_back(child); //to
            graph[child].push_back(i); //from

        }
    }


    vector<int> euler; //save path of DFS
    vector<int> level; //save level of path of DFS
    vector<int> first_occurence(n, -1); //save first occurence of nodes


    //run DFS on graph and save euler and level
    //visited array not needed
    euler.push_back(0); //add root to euler array
    level.push_back(0); //add root level to level array
    first_occurence[0] = 0; // implementation detailð©ó `cU`cUÐy^
    DFS(euler, level, graph, 0, 0, n, 0, first_occurence);

    SegmentTree test(level); //initialize segment tree

    int queries;
    cin >> queries;
    for(int i=0; i<queries; i++)
    {
        int a, b;
        cin >> a >> b;
        int index_i, index_j;
        if (a > b)
        {
            index_i = b;
            index_j = a;
        }
        else
        {
            index_i = a;
            index_j = b;
        }
        //check if index needs to be reversed, error will occur if first is larger than second

        test.c_min_query(first_occurence[index_i], first_occurence[index_j], 0);
        cout << euler[test.m] << endl;
    }




}
