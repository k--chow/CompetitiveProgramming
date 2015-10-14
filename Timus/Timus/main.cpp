#include <iostream>
#include <stdio.h>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{
    boolean stop = false;
    int n, m, previous;
    vector<int> bridges;
    bridges.push_back(-5);
    vector<int> link;
    vector<int> ref;
  scanf("%i", &n);
  scanf("%i", &m);
  for (int i=0; i<n-1; i++)
  {
    int b, fina;
    if (i= 0)
    {
    scanf("%i\t%i\t%i\t%i", &previous, &b, &b, &fina);
    }
    //printf("%i %i\n", a, b);
    else
    {
    scanf("%i\t%i", &b, &fina);
    }
    int c = fina-previous;
    previous = b;
    link.push_back(c);
  }

  for (int i=0; i<m; i++)
  {
    int br;
    scanf("%i", &br);
    bridges.push_back(br);
    //printf("%i\n", br);
  }

  for (int i=1; i<n-1; i++)
  {
    int test = link.at(i);
    boolean found = false;
    while (!found)
    {
    if (std::find(bridges.begin(), bridges.end(), test) - bridges.begin() !=bridges.size())
    {
        ref.push_back(std::find(t.begin(), t.end(), test) - t.begin());
        found = true;
    }
    else
    {
        found = true;
        stop = true;
    }
    }
  }

}


