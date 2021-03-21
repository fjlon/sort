#include<iostream>
using namespace std;

int partition(int* value,int low,int high)
{
    if(!value||low>=high)
        return -1;
    int vCmp = value[low];
    while(low<high)
    {
        while(low<high&&value[high]>=vCmp){
            high--;
        }
        value[low]=value[high];
        while(low<high&&value[low]<=vCmp){
            low++;
        }
        value[high]=value[low];
    }
    value[low]=vCmp;
    return low;
}

int qsort(int* value,int low,int high)
{
    if(!value||low>=high)
        return -1;
    int position = partition(value,low,high);
    qsort(value,low,position-1);
    qsort(value,position+1,high);
    return 0;
}
