#include <iostream>
#include <vector>

using namespace std;

struct Comparator
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.first > b.first;
    }
};

int main()
{
    vector< pair<int, int> > arr;
    arr.push_back(make_pair(5, 5));
    arr.push_back(make_pair(7, 4));
    sort(arr.begin(), arr.end(), Comparator());
    cout << arr[0].first << endl;
}
