#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

double totalDistance;
double cap;
double mpg;
double initialCost;
double carTravel;
int stops;
double stopsA[60];
double prices[60];
double minCost; //for comparisons

//take stop, or go onto next and don't take
//stops+1 is reached
//only compare when reached

int currentStop;
double currentCost;
double currentDistance;
double currentFuel;
//not reached, and illegal steps occuring still!
//same stop is fucking it up
string steps = "";
void stopOrNah(int stop)
{
    //cout << "you called me" << endl;
    int tempStop = currentStop;
    double tempCost = currentCost;
    double tempDist = currentDistance;
    double tempFuel = currentFuel;
    //double tempFuel = currentFuel;
    string steps2 = steps;
    if (stop == stops+1) //reached
    {
            //cout << steps << endl;
            if (currentDistance + carTravel >= totalDistance)
            {
                //cout << steps << endl;
                if (currentCost < minCost)
                {
                    cout << "New Mincost: " << currentCost << endl;
                    cout << steps << endl;
                    minCost = currentCost;
                }
            //cout << minCost << endl;
            }
            else
            {
                cout << "NOT REACHED: " << currentDistance + carTravel << " " << totalDistance << endl;
                cout << steps << endl;
                //currentFuel = 20;
            }

            //cout << "minCost changed" << endl;

        return;
         //cout <<  "called" << endl;

    }
    else
    {
        if (currentFuel >= 0)
        {

        //stopOrNah(stop+1);//don't stop
        bool stopYes = false;
            //try to stop here conditions: more than half of gas gone OR next station too far
        double gasUsed = (stopsA[stop] - stopsA[currentStop])/mpg;
        //cout << "gasUsed " <<  endl;
        if (gasUsed >= cap/2) //more than half gas tank
        {
            stopYes = true;
        }
        else if (stop == stops) //last one to dest
        {
            //cout << "stop is stops" <<endl;
            if (totalDistance - stopsA[currentStop] > carTravel)
            {
                //cout << "totdist " << totalDistance - stopsA[currentStop] << endl;
                stopYes = true;
            }
        }
        else if (stopsA[stop+1] - stopsA[currentStop] > carTravel) //next stop too far
        {
            stopYes = true;
        }


        if (stopYes) //stop
        {
            steps+= to_string(stop);
            //currentFuel = cap;
            currentCost+= gasUsed* prices[stop];
            currentCost += 200;
            currentStop = stop;
            currentDistance = stopsA[stop];
            stopOrNah(stop+1);
        }
        cout << "currentFuel: " <<  currentFuel << " gasUsed: " << gasUsed << endl;
        currentFuel -= (stopsA[stop] - stopsA[stop-1])/mpg;
        steps = steps2;
        currentCost = tempCost;
        currentStop = tempStop;
        currentDistance = tempDist;
        stopOrNah(stop+1);
        currentFuel = tempFuel;
        cout << "recurse: " << "currentFuel: " <<  currentFuel << " gasUsed: " << gasUsed << endl;
        }
        else
        {
            cout << "Illegal NOT ENOUGH FUEL " << currentStop << " to " << stop << endl;

        }

    }





}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<double> ans;
    while (true)
    {
        cin >> totalDistance;

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
            stopsA[0] = 0;
            prices[0] = 0;
            currentStop = 0;
            currentCost = 0;
            currentDistance = 0;
            currentFuel = cap;
            carTravel = cap * mpg;
            minCost = 999999;
            //stopA[0] = 0;
            //prices[0] = 0;
            for(int i=1; i<=stops; i++)
            {
                cin >> stopsA[i];
                cin >> prices[i];

                //cout << stopsA[i] << " " << prices[i] << endl;

            }

            //cout << minCost<< endl;

        }
        //method here
        //cout << "test for stops " << stops;
        if (carTravel >= totalDistance)
        {
            minCost = initialCost;
        }
        else
        {
        stopOrNah(1);
        }
        ans.push_back((int)(minCost+0.5)/100.00 + initialCost);



    }
    //cout << endl;
    for (int i=0; i<ans.size(); i++)
    {
        cout << "Data Set #" << (i+1) << endl;
        cout << "  minimum cost = $" << ans.at(i) << endl;
    }


    }



