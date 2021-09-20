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
const int NMAX=2e5+1;

//ax+by=(a,b),a>0,b>0

void gcd(ll a,ll b,ll &u,ll &v){
    if(b==0){
        u=1;
        v=0;
        return;
    }
    gcd(b,a%b,u,v);
    ll x=v;
    v=u-a/b*v;
    u=x;
}

void solve(){
    ll a,b,u,v;
    cin>>a>>b;
    ll x=__gcd(a,b);
    a/=x,b/=x;
    gcd(a,b,u,v);
    cout<<u<<' '<<v<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int test=1;cin>>test;
    while(test--){
        solve();
    }
}
