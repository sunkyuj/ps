#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

int main()
{


    int channel,broken,i,j,init=100,bNum[10],near;
    cin>>channel>>broken;
    for(i=0;i<broken;i++) cin>>bNum[i];
    if(broken==10){
        cout<<abs(channel-init);
        return 0;
    }
    int ans,upMin,downMin,updown=0,button=0;
    downMin=upMin=channel;
    string buffer;

    while(1){
        int isB1=0,isB2=0;

        buffer=to_string(downMin);
        if(downMin>=0){
            for(i=0;buffer[i]!='\0';i++){
                for(j=0;j<broken;j++){
                    if(buffer[i]-'0'==bNum[j]){
                        isB1=1;
                        break;
                    }
                }
                if(isB1==1){
                    downMin--;
                    break;
                }
            }
            if(isB1==0){
                near=downMin;
                break;
            }
        }

        buffer=to_string(upMin);
        for(i=0;buffer[i]!='\0';i++){
            for(j=0;j<broken;j++){
                if(buffer[i]-'0'==bNum[j]){
                    isB2=1;
                    break;
                }
            }
            if(isB2==1){
                upMin++;
                break;
            }
        }
        if(isB2==0){
            near=upMin;
            break;
        }
    }
    for(i=0;buffer[i]!='\0';i++);
    button=i;
    updown=abs(channel-near);
    ans=updown+button;
    //printf("%d\n%d\n%d\n",near,button,updown);
    cout<<min(ans,abs(channel-init));

    return 0;

}
