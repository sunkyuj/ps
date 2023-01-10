#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>


using namespace std;

int main()
{
    int x,y,i,j,cnt1=0,cnt2=0,m=2500;
    int xpos,ypos;

    string white[8]={
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
    }, black[8]={
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
    }, board[50];

    cin>>y>>x;
    for(i=0;i<y;i++){
        cin>>board[i];
    }

    for(ypos=0;ypos+7<y;ypos++){
        for(xpos=0;xpos+7<x;xpos++){
            for(i=ypos;i<ypos+8;i++){
                for(j=xpos;j<xpos+8;j++){
                    if(board[i][j]!=white[i-ypos][j-xpos]) cnt1++;
                    if(board[i][j]!=black[i-ypos][j-xpos]) cnt2++;
                }
            }
            if(min(cnt1,cnt2)<m) m=min(cnt1,cnt2);
            cnt1=0;cnt2=0;
        }
    }
    cout<<m;



    return 0;
}


