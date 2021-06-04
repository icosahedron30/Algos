#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ull unsigned ll
#define pb push_back
#define epb emplace_back
#define inf 1e9+1
#define linf 1e18+1
using namespace std;
//finding lowest common ancestor in O(logn) with O(nlogn) preparation
vector<vector<int> >g(200001);
int P[200001][21];
vector<int>d(200001);
int n;

void dfs(int v,int e=-1){
    P[v][0]=e;
    for(int to:g[v]){
        if(to==e)continue;
        d[to]=d[v]+1;
        dfs(to,v);
    }
}

void prepare(){
    for(int i=1;i<=n;i++){
        for(int j=0;j<20;j++)P[i][j]=-1;
    }
    dfs(1);
    for(int j=1;j<20;j++){
        for(int i=1;i<=n;i++){
            if(P[i][j-1]!=-1)
            P[i][j]=P[P[i][j-1]][j-1];
        }
    }
}

int lca(int u,int v){
    if(d[u]<d[v])swap(u,v);
    int k=d[u]-d[v];
    while(k){
        int t=log2(k);
        k-=(1<<t);
        u=P[u][t];
    }
    if(u==v)return v;
    for(int j=19;j>=0;j--){
        if(P[u][j]!=P[v][j]){
            u=P[u][j];
            v=P[v][j];
        }
    }
    return P[v][0];
}

void solve(){
    cin>>n;
    for(int i=1;i<=n-1;i++){
        int u,v;cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    prepare();
    int q;cin>>q;
    while(q--){
        int u,v;cin>>u>>v;
        cout<<lca(u,v)<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}
