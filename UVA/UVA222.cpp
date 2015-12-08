#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

//distance
//capacity mpg original cost #gasoline stations
//#gasolinestation lines - distance priceincentspergallon
//-1 end output
double cap;
double mpg;
double totalDistance;
double carTravel;
double initialCost;
double minCost = 100000;
double stopsA[stops];
double prices[stops];
int stops;
//total miles the car can = cap * mpg;
void recurse(int i)
{

        if (totalDistance - distance < carTravel)//do I even need to stop
        {
            double nextStop;
            if (i != (stops.size() - 1))
            {
            nextStop = stops[i+1];
            }
            else
            {
                //can I reach the end?
                if (distance + carTravel >= totalDistance)//yes
                {
                    nextStop = 0;
                }
                //if I can't I have to fill up
                else//no
                {
                    nextStop = totalDistance;
                }

            }
            if ((carTravel/2.0 < (stops[i] - distance) || nextStop - distance > carTravel) && stops[i] - distance <= carTravel)//more than half tank gone, or next station too far
            {//watch nextStop
                double cost = prices[i] * stops[i];
                //if cost is less than min, keep going and set it
                if ((cost + currentCost) < minCost)
                {
                    recurse(stopsA[], prices[], i, distance + (stops[i] - distance), minCost, )
                }
            }
            else
            {
                cout << stops[i] << " Ignored2 because not far enough" << distance << endl;
            }
        }

        else
        {
            cout << stops[i] << " Ignored because reached " << distance << endl;
            if (currentCost < minCost)
            {
                double k = currentCost;
                minCost = k;//doesnt work without pointers
            }//dont set minCost to initial cost..
        }
    }

}

void recurse1(int refer)
{

}

int main()
{

    vector<double> ans;
    while (true)
    {
        cin >> totalDistance;
        //cout << totalDistance << endl;
        if (totalDistance == -1)
        {
            break;
        }
        else
        {





            cin >> cap;
            //cout << cap << endl;
            cin >> mpg;
            cin >> initialCost;
            cin >> stops;

            carTravel = cap * mpg;
            for(int i=0; i<stops; i++)
            {
                cin >> stopsA[i];
                cin >> prices[i];

                //cout << stopsA[i] << " " << prices[i] << endl;

            }

            recurse(0);




        }




    }
    for (int i=0; i< ans.size(); i++)
    {
        cout << ans.at(i) << endl;
    }
    //cost = line 2 element 3
    //miles car travelss - capacity * mpg

    //from start try all possibles within distance
    //only calculate if total mpg > distance travel
    //otherwise return cost
    //driver doesn't stop is only half unless can't make next
    //i can stop at 220, 256, 275, or 277 first
    //write a recursive function
    //basically if its less, set it as least (when reach end)
    //backtrack if not less than half or can't reach next station
    //backtrack if costs more than the point
    /*
    go to 1, backtrack because not less
    go to 2, works now calculate cost, set less if so
    go to 3, works calculate cost, set less if is
    if reached calculate, if not then recurse again
    recursive subproblem - distance from current same applies
    recurse(position in array, inputted miles to minus)
    {
        if (tank >= total- inputted miles to minus) - end
        else
        int i = position in array+1;
        for int newd = distances[i] minus inputted miles
        if (newd > tank/2 || tank < reach distance[i+1] minus inputted miles})
            try it - recurse(position, miles - newd)

    }
    start - recurse(0, 475.6)*/
    }


