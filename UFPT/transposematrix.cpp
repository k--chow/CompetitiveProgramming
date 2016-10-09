#include <algorithm>
#include <vector>
#include <tuple>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
using namespace std;

typedef pair<int, int> P;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie();
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        vector< vector<P> > ans(m+1);

    // Go through all of the rows
    for(int i=1; i<=n; i++)
    {
        int r; scanf("%d", &r);
        // If there are values on this row
        if (r != 0) {
            //get indices
            vector<int> indices;
            for(int j=0; j<r; j++)
            {
                int input; scanf("%d", &input);
                indices.push_back(input);
            }
            //get values
            vector<int> values;
            for(int j=0; j<r; j++)
            {
                int input; scanf("%d", &input);
                values.push_back(input);
                ans[indices[j]].push_back(make_pair(i, values[j]));
            }
        }
    }
    cout << m << " " << n << endl;

    // Go through all of the rows in the answer
    for(int i=1; i<=m; i++)
    {
        // If there aren't any values in this row
        if (ans[i].size() == 0) {
            // Print zero, then an empty line
            cout << ans[i].size() << endl << endl;
        }
        // Otherwise
        else {
            // Print the number of elements
            cout << ans[i].size() << " ";

            // Print the indices
            for(int j=0; j<ans[i].size(); j++)
            {
                P temp = ans[i][j];
                // Output the element index
                cout << temp.first;
                // And a spacer if it's not the last
                if (j != ans[i].size()-1) cout << " ";
            }
            cout << endl;

            // Print the values
            for(int j=0; j<ans[i].size(); j++)
            {
                P temp = ans[i][j];
                // If it's not the first element, output a spacer
                if (j > 0) cout << " ";
                // And output the value
                cout << temp.second;
            }
            cout << endl;
            }

    	}
    }
}
