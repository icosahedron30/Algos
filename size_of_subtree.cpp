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
void dfs(int v,int e=-1);
vector<vector<int> >g(NMAX);
vector<int>dp(NMAX,1);

void dfs(int v,int e){
    for(int to:g[v]){
        if(to!=e)dfs(to,v),dp[v]+=dp[to];
    }
}

void solve(){
    int n;cin>>n;
    for(int i=2;i<=n;i++){
        int x;cin>>x;
        g[x].pb(i);
        g[i].pb(x);
    }
    dfs(1);
    for(int i=1;i<=n;i++){
        cout<<dp[i]<<' ';
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
