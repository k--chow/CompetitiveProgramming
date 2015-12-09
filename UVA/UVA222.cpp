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
double stopA[60];
double prices[60];
int stops;
//total miles the car can = cap * mpg;
/*
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
}*/

//check if we can go there from where we are
bool canStop(int refer1, int refer2)
{
    //dist is greater than half the tank OR
    double dist = stopA[refer2] - stopA[refer1];
    double nextStop;
    if (refer2 == stops)//last stop
    {
        nextStop = totalDistance;
    }else //not last stop
    {
        nextStop = stopA[refer2+1];
    }
    //if can't reach next stop or destination, or too close
    if (dist >= (carTravel/2.0) || nextStop > carTravel)
    {
        return true;
    }

    return false;
}

void recurse1(int refer, int cDistance, int cCost)
{/*
    for loop 1 to 3
    check if still needs distance to reach end
        if end reached - compare cost, return
    if 1 can stop - add to cCost and cDistance, recurse with 2 and 3 - if 2 can stop - recurse with 3 //1 12 13 123
    if 2 can stop - recurse with 3 //2 23
    if 3 can stop - //3
*/
int d = refer;
if (refer+1 != stops)
        {
            d = refer+1;
        }

    for (int i = d; i<stops; i++)
    {

        cout << "cDistance " << cDistance << endl;
        //cout << "start " << refer << " to " << i+1 << endl;
        if (totalDistance - cDistance <= carTravel) //can reach
        {
            cout << "reached " << refer << " " << i << endl;
            //cCost += initialCost;
            if (cCost < minCost)
            {
                minCost = cCost;
                cout << "minCost changed to " << cCost/100.0 << endl;
                //return;
            }
            else
            {
                cout << "minCost not changed to " <<cCost/100.0 << endl;
                //return;
            }
        }
        else
        {
            cout << "Try " << refer << " " << i << endl;

            if (canStop(refer, i))//if can stop from where we are, we must try it
            {
                double extraDistance = stopA[i] - cDistance;// or cDistance for stopsA[refer]
                double extraCost = ((extraDistance/mpg)* prices[i]) + 200;
                cout << "Yes " << refer << " " << i << endl;
                cout << "Go " << i << " " << cDistance+extraDistance << " " << cCost+extraCost << endl;
                recurse1(i, cDistance+extraDistance, cCost+extraCost);//+1 or nah


            }
            else
            {
                cout << "No "<< refer << " " << i << endl;
            }

        }
    }
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
            //stopA[0] = 0;
            //prices[0] = 0;
            for(int i=0; i<stops; i++)
            {
                cin >> stopA[i];
                cin >> prices[i];

                //cout << stopsA[i] << " " << prices[i] << endl;

            }

            recurse1(-1, 0, 0);




        }




    }
    cout << "$" <<minCost/100.00 + initialCost << endl;
    cout << initialCost << endl;

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


