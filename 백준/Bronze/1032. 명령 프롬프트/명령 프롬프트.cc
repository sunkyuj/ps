#include <iostream>
#include <bitset>
#include <string.h>

using namespace std;

int main()
{

    int n,i,j;
    char arr[51][51];
    char ans[51]={0};
    cin >> n;
    for(i=0;i<n;i++){
        cin >> arr[i];
    }
    i=0;
    strcpy(ans,arr[0]);
    for(j=0;j<strlen(arr[0]);j++){
    	for(i=1;i<n;i++){
    		if(arr[i][j]!=arr[i-1][j]){
    			ans[j]='?';
                break;
    		}
    		
    	}
    	
    }
    /*
    for(j=0;arr[i][j]!=NULL;j++){
        for(i=1;i<n;i++){
            if(arr[0][j]!=arr[i][j]){
                ans[j]='?';
                break;
            }
        }
    }
    */


    cout << ans;



    return 0;
}
