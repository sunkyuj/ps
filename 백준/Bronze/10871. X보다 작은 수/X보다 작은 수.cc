#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int n,x,arr[10000];
    int i;
    cin>>n>>x;
    for(i=0;i<n;i++) cin>>arr[i];
    for(i=0;i<n;i++) if(arr[i]<x) cout<<arr[i]<<" ";
    return 0;
}
