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

using namespace std;
string memo[4][4];
void perm(string current, int o, int c)
{
  if (o == 0 && c == 0) {
    cout << current << endl;
    return;
  }
  if (o > 0) {//open
      perm(current + '(', o-1, c);
    if (o < c) {
      perm(current + ')', o, c-1);
    }
  } else {//closed
    perm(current + ')', o, c-1);
  }
}
//store rest of string

int main()
{
  for(int i=0; i<4; i++)
  {

  }
  perm("", 3, 3);
}
