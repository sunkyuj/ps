#include <iostream>
#include <algorithm>

using namespace std;


int k;
int s[12],combi[6];

void dfs(int idx, int depth){
    if(depth==6){
        for(int i=0;i<6;i++) cout<<combi[i]<<" ";
        cout<<"\n";
        return;
    }
    for(int i=idx;i<k;i++) {
        combi[depth]=s[i];
        dfs(i+1, depth+1);
    }

}

int main()
{
    while(1){
        cin>>k;
        if(k==0) break;
        for(int i=0;i<k;i++) cin>>s[i];
        dfs(0,0);
        cout<<"\n";
    }
    return 0;
}

/**

k=12

1 2 3 4 5 6 7 8 9 10 11 12

1 2 3 4 5 6
1 2 3 4 5 7
1 2 3 4 6 7
.
.
.
7 8 9 10 11 12


*/
