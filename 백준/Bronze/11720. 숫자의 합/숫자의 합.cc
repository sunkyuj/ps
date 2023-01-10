#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int n,i,sum=0;
    char nums[101];
    cin>>n;
    cin>>nums;
    for(i=0;i<n;i++) sum+=nums[i]-'0';
    cout<<sum;
    return 0;
}
