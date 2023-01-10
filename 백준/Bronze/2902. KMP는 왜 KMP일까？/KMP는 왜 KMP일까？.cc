#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{

    string s,ans="";
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]>='A'&&s[i]<='Z') ans+=s[i];
    }
    cout<<ans;

    return 0;
}


