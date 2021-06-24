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

// finding maximum distance to another node

const int NMAX=200001;
vector<vector<int> >g(NMAX);
int dp[NMAX][3];

void dfs(int v,int e=-1){
    bool ind=false;
    for(int to:g[v]){
        if(to!=e)dfs(to,v),ind=true;
    }
    if(!ind)return;
    for(auto to:g[v]){
        if(dp[v][0]<dp[to][0]+1)dp[v][0]=dp[to][0]+1,dp[v][2]=to;
    }
    for(int to:g[v]){
        if(dp[v][1]<dp[to][0]+1&&dp[v][2]!=to)dp[v][1]=dp[to][0]+1;
    }

}

void DFS(int v,int e=-1){
    for(int to:g[v]){
        if(to==e)continue;
        if(dp[v][2]==to){
            if(dp[to][0]<dp[v][1]+1)dp[to][0]=dp[v][1]+1,dp[to][1]=dp[to][0],dp[to][2]=v;
            else{
                if(dp[to][1]<dp[v][1]+1)dp[to][1]=dp[v][1]+1;
            }
        }
        else{
            if(dp[to][0]<dp[v][0]+1)dp[to][0]=dp[v][0]+1,dp[to][1]=dp[to][0],dp[to][2]=v;
            else{
                if(dp[to][1]<dp[v][0]+1)dp[to][1]=dp[v][0]+1;
            }
        }
        DFS(to,v);
    }
}

void solve(){
    int n;cin>>n;
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1);
    DFS(1);
    for(int i=1;i<=n;i++)cout<<dp[i][0]<<' ';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
