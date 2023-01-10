#include <iostream>
#include <string.h>
 
using namespace std;
 
int main()
{
    int i,j,max_len=0;
    char str[5][16];
    for(i=0;i<5;i++){
        cin >> str[i];
    }
    for(i=0;i<5;i++){
        if(max_len<strlen(str[i]))
            max_len=strlen(str[i]);
    
    }
    
    for(j=0;j<max_len;j++){
        for(i=0;i<5;i++){
            if(strlen(str[i])>=j+1)
                cout << str[i][j];
        }
    }
    return 0;
}