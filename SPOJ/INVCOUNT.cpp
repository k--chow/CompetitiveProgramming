#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <cstring>
#include <queue>
using namespace std;
int arr[200001];
int arr2[200001];
long long cnt;

void m(int left, int mid, int right)
{
    //left array is left to mid, already sorted

    //right array is mid+1 to right, already sorted

    //new array is in range left to right
    int i = left, j = mid+1, k = left;
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            arr2[k++] = arr[i++];
        }
        else
        {
            arr2[k++] = arr[j++];
            cnt+= (mid - i + 1);
            //cout << "Count updated: " << cnt << endl;
        }
    }

    //check for leftovers in both arrays
    while (i <= mid)//left still has some
    {
        arr2[k++] = arr[i++];
    }

    while (j <= right) //right still has somee
    {
        arr2[k++] = arr[j++];
    }

    //copy array elements over
    k = left;
    while (k <= right)
    {
        arr[k] = arr2[k];
        k++;
    }


}

void mergeSort(int left, int right)
{
    if (right - left >= 1)
    {
        //cout << "Mergesort: " << left << " " << right << endl;
    //stop on < 2
    int mid = (left+right)/2;


    mergeSort(left, mid);
    mergeSort(mid+1, right);
    //merge
    m(left, mid, right);
    }

}



int main()
{
    int cases;
    cin >> cases;
    for(int i=0; i<cases; i++)
    {
        //cout << "hi" << endl;
        cnt = 0;
        int length;
        cin >> length;
        for(int j=0; j<length; j++)
        {
            int n;
            cin >> n;
            arr[j] = n;
        }
        mergeSort(0, length-1);
        cout << cnt << endl;
    }
}
