#include <bits/stdc++.h>

#define all(x) x.begin(),x.end()
#define rep(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;

typedef pair<string, string> pss;

int total;
unordered_map<string, vector<string>> conn;
unordered_map<string, vector<int>> visited;
vector<string> answer;

void dfs(vector<string> route){
    if(route.size() == total+1){
        answer = route;
        return;
    }
    if(!answer.empty()) return;
    
    string from = route.back();
    
    rep(i,0,conn[from].size()){
        string to = conn[from][i];
        if(!visited[from][i]){
            visited[from][i] = 1;
            route.push_back(to);
            dfs(route);
            route.pop_back();
            visited[from][i] = 0;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    total = tickets.size();
    
    for(auto &vs:tickets){
        string a = vs[0], b = vs[1];
        conn[a].push_back(b);
    }
    for(auto &[key, v]: conn){
        sort(all(v));
        visited[key] = vector<int>(v.size());
    }
    vector<string> route = {"ICN"};
    dfs(route);
    return answer;
}