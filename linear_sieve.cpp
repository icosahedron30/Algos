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

vector<ll>lp(NMAX,0);
vector<ll>pr;

void sieve(ll n){
    for(int i=2;i<=n;i++){
        if(lp[i]==0){
            pr.pb(i);
            lp[i]=i;
        }
        for(int j=0;j<pr.size()&&pr[j]<=lp[i]&&pr[j]*lp[i]<=n;j++)lp[pr[j]*i]=pr[j];
    }
}


void solve(){
    int n;cin>>n;
    sieve(n);
    for(int i=1;i<=n;i++){
        cout<<lp[i]<<' ';
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("in.in","r",stdin);freopen("out.out","w",stdout);
    int test=1;//cin>>test;
    while(test--){
        solve();
    }
}
