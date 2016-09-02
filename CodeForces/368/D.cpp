#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <time.h>
using namespace std;

int main()
{
  int arr[1000][1000];
  for(int i=0; i<100000; i++)
  {
    for(int j=0; j<1000; j++)
    {
      arr[i][j] = 1;
    }
  }

  int arrB[1000][1000];
  clock_t start, end;
  start = clock();
  for(int i=0; i<1000; i++)
  {
    for(int j=0; j<1000; j++)
    {
      arrB[i][j] = arr[i][j];
    }
  }
  end = clock();
  float diff =((float)end - (float)start);
  cout << diff << endl;

  start = clock();
  for(int i=0; i<1000; i++)
  {
    for(int j=0; j<1000; j++)
    {
      arrB[i][j] = 1;
    }
  }
  end = clock();
  diff =((float)end - (float)start);
  cout << diff << endl;



}
