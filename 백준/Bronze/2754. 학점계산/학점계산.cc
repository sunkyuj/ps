#include <iostream>

using namespace std;

int main() {
    string s;
    cin>>s;
    if(s=="F") cout<<"0.0";
    else{
        int arr[4] = {4,3,2,1};
        float ans = arr[s[0]-'A'];
        if(s[1]=='+') ans+=0.3;
        else if(s[1]=='-') ans -=0.3;
        printf("%.1f",ans);       
    }

    return 0;
}
