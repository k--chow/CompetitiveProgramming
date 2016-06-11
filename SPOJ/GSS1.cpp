#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
using namespace std;



class SegmentTree
{
    public:
    int s; //size
    vector<int> mx;
    vector<int> left;
    vector<int> right;
    vector<int> backing;


    SegmentTree(vector<int> arr)
    {
        //set up arrays
        backing = arr;
        s = arr.size();
        for(int i=0; i<4*s; i++)
        {

            mx.push_back(0);
            left.push_back(0);
            right.push_back(0);
        }

        //cout << backing[0] << endl;
        build(0, s-1, 0);
    }


    //query method isn't optimized for max queries
    int query(int left_idx, int right_idx, int index)//recursive query with color noding
    {
        //cout << "hi" << endl;
        //index is all within query range- return
        if (left[index] >= left_idx && right[index] <= right_idx)
        {
            return mx[index];
        }

        //not part at all - stop or return 0

        else if (left[index] > right_idx || right[index] < left_idx)
        {
            return -16000;
        }

        //partial - half it
        else
        {
            cout << "hi" << endl;
            return max(query(left_idx, right_idx, ((2*index) + 1)), query(left_idx, right_idx, (2*index) +2 ));
        }





    }


    //recursively build the segment tree
    void build(int left_index, int right_index, int index)
    {
        left[index] = left_index;
        right[index] = right_index; //for later queries

        if (left_index == right_index) //base case as self
        {
            mx[index] = backing[left_index];
            return;
        }


        build( left_index, (left_index + right_index) / 2, (2 * index ) + 1);//left half
        build( ((left_index + right_index)/2)+1, right_index, (2 * index) + 2); //right half

        mx[index] = max(mx[2*index + 1], mx[2*index + 2]);//just max of left and right
    }

};//stupid variable naming



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //segment tree
    int arraSize;
    cin >> arraSize;
    vector<int> arra;
    for(int i=0; i<arraSize; i++)
    {
        int a;
        cin >> a;
        arra.push_back(a);
    }
    SegmentTree test(arra);
    int nQueries;
    cin >> nQueries;
    for(int i=0; i<nQueries; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << test.query(a, b, 0) << endl;
    }

}
