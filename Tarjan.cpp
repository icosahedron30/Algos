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

vector<int>t_in(200001),low(200001);
vector<bool>used(200001);
vector<vector<int> >g(200001);
int timer=0;
vector<pii>bridges;
void TarjanDFS(int v,int e=-1){
    used[v]=true;
    t_in[v]=low[v]=timer++;
    for(int to:g[v]){
        if(to==e)continue;
        if(used[to]){
            low[v]=min(low[v],t_in[to]);
        }
        else{
            TarjanDFS(to,v);
            low[v]=min(low[v],low[to]);
            if(t_in[v]<low[to])bridges.epb(v,to);
        }
    }
}

void StupidGuy(){
    int n;cin>>n;
    int m;cin>>m;
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for(int i=1;i<=n;i++){
        if(!used[i])TarjanDFS(i);
    }
    cout<<bridges.size()<<"\n";
    for(pii to:bridges){
        cout<<to.f<<' '<<to.s<<"\n";
    }
}

int main(){
    StupidGuy();
    return 0;
}
