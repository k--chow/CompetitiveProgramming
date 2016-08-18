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

typedef long long ll;
typedef vector <int> vi;
typedef vector <long long> vl;
vl v1(11005, 0);
vl v2(11005, 0);

int main()
{
  std::ios::sync_with_stdio(false);
	cin.tie(NULL);
  while(1) {
    int n1, n2;

    cin >> n1;
    if (n1 == 0) break;
    for(int i=0; i<n1; i++) {
      int e; cin >> e;
      v1[i] = e;
    }

    cin >> n2;
    for(int i=0; i<n2; i++) {
      int e; cin >> e;
      v2[i] = e;
    }

    long long topSum = 0, botSum = 0, runningIndex = 0, currentIndex = 0;
    long long totalSum = 0;
    vl *v3, *v4;
    int s1, s2;
    if (n1 > n2) {
      v3 = &v1;
      v4 = &v2;
      s1 = n1;
      s2 = n2;
    } else {
      v3 = &v2;
      v4 = &v1;
      s1 = n2;
      s2 = n1;
    }

    //v3 > v4
    for(;runningIndex < s1; runningIndex++) {
      int value = (*v3)[runningIndex];
      topSum += value;
      int index = lower_bound(v4->begin(), v4->begin() + n2, value) - v4->begin();
      //cout << value << " " << (*v4)[index-1] << endl;
      if ((*v4)[index] == value) {
        for(;currentIndex < index; currentIndex++) {
          botSum+= (*v4)[currentIndex];
        }
        //cout << topSum << " a " << botSum << endl;
        totalSum += max(topSum, botSum);
        topSum = 0, botSum = 0;

      }
    }

    if (topSum != 0) {
      //cout << "called" << endl;
      for(;currentIndex < s2; currentIndex++) {
        botSum += (*v4)[currentIndex];
      }
      totalSum+= max(topSum, botSum);
    }
    cout << totalSum << endl;
  }
}
