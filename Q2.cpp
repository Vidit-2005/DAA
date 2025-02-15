#include<bits/stdc++.h>
using namespace std;
void index(int arr[],int size)
{
    int i,j,k;
    for(k=0;k<size;k++)
    {
        i=0,j=size-1;
        while(i+1<j)
        {
            if(arr[i]+arr[j] > arr[k])
                j--;
            else if(arr[i]+arr[j] < arr[k])
                i++;
            else
                break;
        }
        if(arr[i]+arr[j] == arr[k])
        {
            cout<<"i= "<<i<<"\tj= "<<j<<"\tk= "<<k<<endl;
            return;
        }
        else if(k+1==size)
        {
            cout<<"Element not found!!!";
        }
    }
}


int main()
{
    int arr[]={64,69,82,95,99,107,113,141,171,350,369,400,511,590,666};
    int size=sizeof(arr)/sizeof(arr[0]);
    index(arr,size);
    return 0;
}
