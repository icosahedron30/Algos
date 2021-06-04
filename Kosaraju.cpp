#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ull unsigned ll
#define pb push_back
#define epb emplace_back
using namespace std;
//finding SCC in directed graph
vector<vector<int> >g(200001);
vector<vector<int> >g_rev(200001);

stack<int>s;
vector<bool>used(200001,false);
vector<int>comp;

void DFS(int v){
    used[v]=true;
    for(int to:g[v]){
        if(!used[to])DFS(to);
    }
    s.push(v);
}

void Reversed_DFS(int v){
    used[v]=true;
    comp.pb(v);
    for(int to:g_rev[v]){
        if(!used[to])Reversed_DFS(to);
    }
}

void StupidGuy(){
    int n;cin>>n;
    int m;cin>>m;
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        g[u].pb(v);
        g_rev[v].pb(u);
    }
    for(int i=1;i<=n;i++){
        if(!used[i])DFS(i);
    }
    fill(used.begin(),used.end(),false);
    while(!s.empty()){
        int v=s.top();

        s.pop();
        if(!used[v]){
            Reversed_DFS(v);
            for(int i:comp)cout<<i<<' ';
            cout<<"\n";
            comp.clear();
        }

    }
}

int main(){
    StupidGuy();
    return 0;
}
