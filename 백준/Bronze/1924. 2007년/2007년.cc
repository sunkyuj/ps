#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main()
{
    char yoil[7][4]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
    int month_days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int month,day,index,i,daySum=0;

    cin>>month>>day;
    for(i=1;i<month;i++){
        daySum+=month_days[i];
    }
    index=(daySum+day)%7;
    cout<<yoil[index];


    return 0;
}

