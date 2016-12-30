#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct Comparator
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.first > b.first;
    }
};
/*
int solution(string &A) {
    long long caps = 0, left = 0, ans = -1;
    for(int i=0; i<=A.size(); i++)//watch ending
    {
        if (isdigit(A[i]) || i == A.size())
        {
            if (caps > 0) ans = max(ans, i-left);
            caps = 0;
            left = i+1;
        }
        else if (isupper(A[i]))
        {
            caps++;
        }
    }
    return ans;
}*/
/*
int solution(vector<int> &A, vector<int> &B, int M, int X, int Y) {
    int ans = 0;

    //get number
    int i=0;
    while (i < A.size())
    {
        int currentNumber = i;
        long long currentWeight = Y;
        unordered_set<int> floors;
        //for loop get current
        for(;(i-currentNumber)<X ;i++)
        {
            if (currentWeight - A[i] < 0 ) {//dont take
                break;
            }
            currentWeight -= A[i];
            floors.insert(B[i]);
        }
        //take i
        ans += floors.size() + 1;
    }
    return ans;
}*/

int solution(vector<int> &A, vector<int> &B, int M, int X, int Y) {
 int ans = 0;

    //get number
    int i=0, size = A.size();
    while (i < size)
    {
        int currentNumber = i;
        long long currentWeight = Y;
        unordered_set<int> floors;
        //for loop get current
        for(;(i-currentNumber)<X ;i++)
        {
            if (currentWeight - A[i] < 0 ) {//dont take
                break;
            }
            currentWeight -= A[i];
            floors.insert(B[i]);
        }
        //take i
        ans += floors.size() + 1;

    }
    return ans;
}

int main()
{
    vector<int> C = {40, 40, 100, 80, 20};
    vector<int> D = {3, 3, 2, 2, 3};
    vector<int> A = {60, 80, 40};
    vector<int> B = {2, 3, 5};
    cout << solution(A, B, 5, 2, 200) << endl;
    cout << solution(C, D, 3, 5, 200) << endl;
}
