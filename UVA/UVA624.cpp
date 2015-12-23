//20 tracks
//N minute track
//get as close as possible to N
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>
using namespace std;

int N;
int T;
int tim[20];
string steps; //""
string rightsteps;
int currentSum; //0
int highestSum;
void recurse(int track)
{
    int tempSum = currentSum;
    string tempSteps = steps;

    //if reach N in terms of reference
    if (track == T)
    {
        //check if N or if greater than current
        if (currentSum > highestSum && currentSum < N+1)
        {
            //we have a winner
            //cout << "Winner: " << currentSum << endl;
            //cout << "Steps: " << steps << endl;
            highestSum = currentSum;
            rightsteps = steps;
        }
        else
        {
            //cout << "NotWinner: " << currentSum << endl;
        }
    }
    else
    {
        //if sum can go there
        if (currentSum < N+1)
        {
            //cout << "Trying: " << steps << " to " << tim[track] << endl;
            //take
            currentSum +=tim[track];
            steps+= to_string(tim[track]) + " ";
            recurse(track+1);
            //don't take
            currentSum = tempSum;
            steps = tempSteps;
            recurse(track+1);

        }
        else
        {
            //cout << steps << " < " << tim[track] << endl;
        }
    }


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string line;
    //cout << endl;
    vector<string> ans;
    while (scanf('%d', &line) == 1)
    {
        N = line
        string tt;
        cin >> tt;
        T = atoi(tt.c_str());
        for(int i=0; i < T; i++)
        {

            cin >> tim[i];
            //cout << tim[i];
        }
        //cout << endl;

        //cout << "T: " << T << endl;
        steps = "";
        currentSum = 0;
        highestSum = 0;
        //run recursive backtracking algorithm
        recurse(0);
        ans.push_back(rightsteps + "sum:" + to_string(highestSum));
        //cout << rightsteps<< endl;
    }
    //cout << endl;
    for(int i=0; i<ans.size(); i++)
    {
        cout << ans.at(i) << endl;
    }
}
