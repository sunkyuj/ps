#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 9999999

using namespace std;

typedef pair<int,int> pii;
typedef pair<int,pii> piii;

int root[101];

int find(int v){
    if(v==root[v])
        return v;
    return root[v] = find(root[v]);
}

void uni(int v1, int v2){
    int r1 = find(v1), r2 = find(v2);
    if(r1>r2){
        int tmp = r1;
        r1 = r2;
        r2 = tmp;
    }
    root[r2] = r1;
}



int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    for(int i=0;i<n;i++) root[i] = i;
    vector<piii> edges;
    for(auto &v: costs){
        int a = v[0], b = v[1], c= v[2];
        edges.push_back({c,{a,b}});
    }
    
    sort(edges.begin(), edges.end());
    int cnt=0;
    
    for(int i=0; cnt<n-1;i++){
        int cost = edges[i].first, a = edges[i].second.first, b = edges[i].second.second;
        // cout << cost << " " << a  << " "<< b<<endl;
        if(find(a) == find(b)) continue;
        
        uni(a,b);
        answer += cost;
        cnt++;
    }
    
    // for(auto &[cost, p]: edges){
    //     cout<<cost<<" "<<p.first << " " << p.second <<"\n";
    // }
    
    return answer;
}