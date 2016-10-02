#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <queue>
#include <iomanip>
#include <map>
using namespace std;

bool pairCompare(const std::pair<int, int>& firstElem, const std::pair<int, int>& secondElem) {
  return firstElem.first < secondElem.first;

}

int main()
{
  int pairs; cin >> pairs;
  vector<pair<int, int> > arr;
  for(int i=0; i<pairs; i++)
  {
    int a, b;cin >> a >> b;
    arr.push_back(make_pair(a, b));
  }
  bool ans = true;
  //sort
  sort(arr.begin(), arr.end(), pairCompare);
  for(int j=0; j<pairs; j++)
  {
    int start = arr[j].first;
    int end = arr[j].second;

    int count = end - start; //88
    if (start == end) count = 1;
    if (count >= 90) {
      //false
      ans = false;
      break;
    }
    for(int k=j+1; k<pairs; k++)
    {
          int newStart = arr[k].first;
          int newEnd = arr[k].second;
          int threshold = start + 180 - 1;
          if ((threshold - newStart) > 0 ) {
            count += (threshold - newStart);
            if (threshold > newEnd)
            {
                count -= (threshold - newEnd);

            }
            }
            if (threshold == newStart) {count++;}
            else if (threshold == newEnd) {count++;}



    }
    //cout << count << endl;
    if (count >= 90) {
      ans = false;
      break;
    }
  }
  if (ans) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
