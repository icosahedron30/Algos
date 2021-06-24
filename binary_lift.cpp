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
vector<int>dp(NMAX,1);
int a[NMAX][20];
void dfs(int v,int e){
    a[v][0]=e;
    for(int to:g[v]){
        if(to!=e)dfs(to,v),dp[v]+=dp[to];
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

void solve(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        int u,v;cin>>u>>v;
        g[u].pb(v);g[v].pb(u);
    }
    prepare();
    while(q--){
        int v,k;
        cin>>v>>k;
        cout<<binary_lift(v,k)<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
