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
#include <queue>
using namespace std;

int main()
{
    int N; cin >> N;
    for(int x=0; x<N; x++)
    {

        int B; cin >> B;
        int SG, SB; cin >> SG >> SB;
        priority_queue<int> Gr, Bl;
        for(int i=0; i<SG; i++)
        {
            int s; cin >> s;
            Gr.push(s);
        }
        for(int i=0; i<SB; i++)
        {
            int s; cin >> s;
            Bl.push(s);
        }
        while (!Gr.empty() && !Bl.empty())
        {
            //take B from each
            stack<int> blueReinsert;
            stack<int> greenReinsert;
            //add back?
            for(int j=0; j<B; j++)
            {
                int blue = 0, green = 0;
                if (!Bl.empty()) {
                    blue = Bl.top();
                    Bl.pop();
                }
                if (!Gr.empty()) {
                    green = Gr.top();
                    Gr.pop();
                }
                if (blue > green) {
                    blueReinsert.push(blue - green);
                }
                if (green > blue) {
                    greenReinsert.push(green - blue);
                }
            }
            while (!blueReinsert.empty())
            {
                Bl.push(blueReinsert.top());
                blueReinsert.pop();
            }

            while (!greenReinsert.empty())
            {
                Gr.push(greenReinsert.top());
                greenReinsert.pop();
            }

            //reinsert
        }

        if (Gr.empty() && Bl.empty()) {
            cout << "green and blue died" << endl;
        } else if (Gr.empty())
        {
            cout << "blue wins" << endl;
            while (!Bl.empty()) {
                cout << Bl.top() << endl;
                Bl.pop();
            }
        } else {
            cout << "green wins" << endl;
            while (!Gr.empty()) {
                cout << Gr.top() << endl;
                Gr.pop();
            }
        }
        if (x != N-1) cout << endl;
    }

}
