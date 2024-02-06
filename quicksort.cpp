#include <bits/stdc++.h>
using namespace std;

int f(vector<int> &a,int low,int high)
{
    int pivot=a[low];
    int i=low;
    int j=high;
    while(i<j)
    {
        while(a[i]<=pivot)
        {
            i++;
        }
        while(a[j]>pivot)
        {
            j--;
        }
        if(i<j)
        swap(a[i],a[j]);
    }
    swap(a[low],a[j]);
    return j;
}

void qs(vector<int> &a,int low,int high)
{
    if(low<high)
    {
        int partition=f(a,low,high);
        qs(a,low,partition-1);
        qs(a,partition+1,high);
    }
}

int main()
{
    vector<int> a={4,6,2,5,7,9,1,3};
    qs(a,0,a.size()-1);
    for(int i=0;i<a.size();i++)
    cout<<a[i]<<endl;
    return 0;
}
