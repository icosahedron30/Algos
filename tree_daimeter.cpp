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

// tree diameter

const int NMAX=200001;
vector<vector<int> >g(NMAX);

int dp[NMAX];
priority_queue<int>length[NMAX];

void dfs(int v,int e=-1){
    for(int to:g[v]){
        if(to==e)continue;
        dfs(to,v);
        length[v].push(dp[to]);
        dp[v]=max(dp[v],dp[to]+1);
    }
}


void solve(){
    int n;cin>>n;
    if(n==1){
        cout<<0;
        return;
    }
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        g[u].pb(v),g[v].pb(u);
    }
    dfs(1);
    int mx=length[1].top()+1;
    for(int i=1;i<=n;i++){
        if(length[i].size()<=1)continue;
        int x=length[i].top();length[i].pop();int y=length[i].top();
        mx=max(mx,x+y+2);
    }
    cout<<mx<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
