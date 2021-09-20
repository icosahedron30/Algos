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

int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}

void solve(){
    int a,b;cin>>a>>b;
    cout<<gcd(a,b)<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int test=1;cin>>test;
    while(test--){
        solve();
    }
}
