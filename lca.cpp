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
const int NMAX=200001;
int n,q;
void dfs(int v,int e=-1);
vector<vector<int> >g(NMAX);
vector<int>dp(NMAX,0);
int a[NMAX][20];
void dfs(int v,int e){
    a[v][0]=e;
    for(int to:g[v]){
        if(to!=e)dp[to]=dp[v]+1,dfs(to,v);
    }
}
 
void prepare(){
    dfs(1);
    for(int i=1;i<=19;i++){
        for(int j=1;j<=n;j++)a[j][i]=-1;
    }
    for(int j=1;j<20;j++){
        for(int i=1;i<=n;i++){
            if(a[i][j-1]!=-1)a[i][j]=a[a[i][j-1]][j-1];
        }
    }
}
 
int binary_lift(int v,int k){
    for(int j=0;j<20;j++){
        if(k&(1<<j))v=a[v][j];
        if(v==-1)break;
    }
    return v;
}
 
int lca(int v,int u){
    if(dp[v]>dp[u])swap(u,v);
    int x=dp[u]-dp[v];
    u=binary_lift(u,x);
    if(u==v)return v;
    for(int j=19;j>=0;j--){
        if(a[u][j]!=a[v][j]){
            v=a[v][j];
            u=a[u][j];
        }
    }
    return a[u][0];
}
 
void solve(){
    cin>>n>>q;
    for(int i=2;i<=n;i++){
        int x;cin>>x;
        g[x].pb(i);
        g[i].pb(x);
    }
    prepare();
    while(q--){
        int u,v;
        cin>>u>>v;
        cout<<lca(u,v)<<"\n";
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
