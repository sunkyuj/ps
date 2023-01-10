#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int a,b,c,ans;
    cin>>a>>b>>c;
    ans=(a>b)?(c>a?a:(c>b?c:b)):(c>b?b:(a>c?a:c));
    cout<<ans;
    return 0;
}
