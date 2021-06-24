#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ull unsigned ll
#define epb emplace_back
#define pb push_back
#define inf 1e9+1
#define linf 1e18+1
using namespace std;

// sum of distances to every other node

const int NMAX=200001;
vector<vector<int> >g(NMAX);
vector<ll>sz(NMAX,1);
ll dp[NMAX];


void dfs(int v,int e=-1){
    for(int to:g[v]){
        if(to==e)continue;
        dfs(to,v);
        sz[v]+=sz[to];
        dp[v]+=dp[to]+sz[to];
    }
}

void DFS(int v,int e=-1){
    for(int to:g[v]){
        if(to==e)continue;
        dp[to]=dp[v]+sz[1]-2*sz[to];
        DFS(to,v);
    }
}

void solve(){
    int n;cin>>n;
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        g[u].pb(v),g[v].pb(u);
    }
    dfs(1);
    DFS(1);
    for(int i=1;i<=n;i++){
        cout<<dp[i]<<' ';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
