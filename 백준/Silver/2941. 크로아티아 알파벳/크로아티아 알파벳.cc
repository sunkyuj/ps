#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>


using namespace std;

int main()
{

    int cnt=0,i;
    string s;
    cin>>s;
    int realLength=s.length();
    for(i=0;i<s.length()-1;i++){
        if(s[i]=='c'){
            if(s[i+1]=='='||s[i+1]=='-') realLength--;
        }
        else if(s[i]=='d'){
            if(s[i+1]=='z'){
                if(s[i+2]=='='){
                    realLength-=2;
                    i++;
                }
            }
            else if(s[i+1]=='-') realLength--;

        }
        else if(s[i]=='l'){
            if(s[i+1]=='j') realLength--;
        }
        else if(s[i]=='n'){
            if(s[i+1]=='j') realLength--;
        }
        else if(s[i]=='s'){
            if(s[i+1]=='=') realLength--;
        }
        else if(s[i]=='z'){
            if(s[i+1]=='=') realLength--;
        }
    }

    cout<<realLength;


    return 0;
}


