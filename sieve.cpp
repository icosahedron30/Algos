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

vector<bool>used(NMAX);
vector<int>pr;

void sieve(ll n){
    for(ll i=2;i<=n;i++){
        if(!used[i]){
            pr.pb(i);
            used[i]=true;
            for(ll j=i*i;j<=n;j+=i)used[j]=true;
        }
    }
}

void solve(){
    int n;cin>>n;
    sieve(n);
    for(int to:pr)cout<<to<<' ';

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int test=1;//cin>>test;
    while(test--){
        solve();
    }
}
