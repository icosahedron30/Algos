#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define f first
#define s second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define epb emplace_back
#define inf 1e9+1
#define linf 1e18+1

using namespace std;

//MST with kruskul


int NMAX=2000001;
vector<int>p(NMAX);
vector<int>sz(NMAX);

struct Edge{
    int u,v,c;
    Edge(){
        u=v=c;
    }
    Edge(int u,int v,int c):u(u),v(v),c(c){}
};

vector<Edge>edges;

void make_set(int v){
    p[v]=v;
    sz[v]=1;
}

int find_set(int v){
    if(v==p[v])return v;
    return p[v]=find_set(p[v]);
}

void union_sets(int a,int b){
    a=find_set(a);
    b=find_set(b);
    if(a!=b){
        if(sz[a]<sz[b])swap(a,b);
        sz[a]+=sz[b];
        p[b]=a;
    }
}

bool comp(Edge a,Edge b){
    return a.c<b.c;
}

void solve(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        make_set(i);
    }
    for(int i=1;i<=m;i++){
        int u,v,c;cin>>u>>v>>c;
        edges.epb(u,v,c);
    }
    vector<Edge>ans;
    sort(edges.begin(),edges.end(),comp);
    for(Edge E:edges){
        if(find_set(E.v)!=find_set(E.u))union_sets(E.v,E.u),ans.pb(E);
    }
    for(Edge E:ans){
        cout<<E.v<<' '<<E.u<<' '<<E.c<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}
