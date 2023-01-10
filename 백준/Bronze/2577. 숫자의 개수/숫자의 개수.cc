#include <iostream>
char* itoa(int val, char * buf, int radix) {

	char* p = buf;

	while(val) {

		if(radix <= 10)
			*p++ = (val % radix) + '0';

		else {
			int t = val % radix;
			if (t <= 9)
				*p++ = t + '0';
			else
				*p++ = t - 10 + 'a';
		}

		val /= radix;
	}

	*p = '\0';
	//reverse(buf);
	return buf;
}
using namespace std;


int main()
{
    int a,b,c,i;
    cin >> a >> b >> c;
    int x=a*b*c;
    char arr[100];
    int num[10]={0};

    itoa(x,arr,10);

    for(i=0;arr[i]!=NULL;i++){
       if(arr[i]=='0')
        num[0]++;
       if(arr[i]=='1')
        num[1]++;
       if(arr[i]=='2')
        num[2]++;
       if(arr[i]=='3')
        num[3]++;
       if(arr[i]=='4')
        num[4]++;
       if(arr[i]=='5')
        num[5]++;
       if(arr[i]=='6')
        num[6]++;
       if(arr[i]=='7')
        num[7]++;
       if(arr[i]=='8')
        num[8]++;
       if(arr[i]=='9')
        num[9]++;
    }
    for(i=0;i<10;i++)
        cout << num[i] << endl;
    return 0;
}
