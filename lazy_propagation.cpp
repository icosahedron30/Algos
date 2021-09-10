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

//range addition and range maximum query

const int NMAX=1e5+1;
ll t[4*NMAX],lazy[4*NMAX];
ll a[NMAX];

void push(int v){
    if(!lazy[v])return;
    lazy[v*2]+=lazy[v];
    lazy[2*v+1]+=lazy[v];
    t[2*v]+=lazy[v];
    t[2*v+1]+=lazy[v];
    lazy[v]=0;
}

void build(int v,int l,int r){
    if(l==r){
        t[v]=a[l];
        return;
    }
    int m=(l+r)/2;
    build(2*v,l,m);build(2*v+1,m+1,r);
    t[v]=max(t[v*2],t[2*v+1]);
}

void update(int v,int l,int r,int st,int fin,ll val){
    if(l>fin||r<st)return;
    if(l>=st&&r<=fin){
        t[v]+=val;
        lazy[v]+=val;
        return;
    }
    push(v);
    int m=(l+r)/2;
    update(2*v,l,m,st,fin,val);
    update(2*v+1,m+1,r,st,fin,val);
    t[v]=max(t[2*v],t[2*v+1]);
}

ll get(int v,int l,int r,int st,int fin){
    if(l>fin||r<st)return 0;
    if(l>=st&&r<=fin){
        return t[v];
    }
    push(v);
    int m=(l+r)/2;
    ll x=get(2*v,l,m,st,fin),y=get(2*v+1,m+1,r,st,fin);
    return max(x,y);
}

void solve(){
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>a[i];
    build(1,1,n);
    while(q--){
        int test;cin>>test;
        cout<<"\n";
        if(test==1){
            int l,r;ll val;cin>>l>>r>>val;
            update(1,1,n,l,r,val);
        }
        if(test==2){
            int l,r;cin>>l>>r;
            cout<<get(1,1,n,l,r)<<"\n";;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //freopen("in.in","r",stdin);freopen("out.out","w",stdout);
    int test=1;//cin>>test;
    while(test--){
        solve();
    }
}

