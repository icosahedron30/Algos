#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define pii pair<int,int>
#define pll pair<ll,ll.
#define ull unsigned ll
#define epb emplace_back
#define inf 1e9+1
#define linf 1e18+1
using namespace std;
//segment tree for sum
struct Vertex{
    int sum=0;
    Vertex *l,*r;
    Vertex(int sum):l(nullptr),r(nullptr),sum(sum){
    }
    Vertex(Vertex *l,Vertex *r):l(l),r(r),sum(0){
        if(l!=nullptr)sum+=l->sum;
        if(r!=nullptr)sum+=r->sum;
    }
};
vector<int>a(200001);
Vertex *build(int l,int r){
    if(l==r){
        return new Vertex(a[l]);
    }
    int m=(l+r)/2;
    return new Vertex(build(l,m),build(m+1,r));
}

Vertex *update(Vertex *v,int l,int r,int pos,int nw){
    if(l==r){
        delete(v);
        return new Vertex(nw);
    }
    int m=(l+r)/2;
    if(pos<=m){
        Vertex *k=new Vertex(update(v->l,l,m,pos,nw),v->r);
        delete(v);
        return k;
    }
    Vertex *k=new Vertex(v->l,update(v->r,m+1,r,pos,nw));
    delete(v);
    return k;
}

int get(Vertex *v,int l,int r,int tl,int tr){
    if(l>r)return 0;
    if(l==tl&&r==tr){
        return v->sum;
    }
    int tm=(tl+tr)/2;
    return get(v->l,l,min(r,tm),tl,tm)+
                get(v->r,max(tm+1,l),r,tm+1,tr);
}

void solve(){
    int n;cin>>n;
    int q;cin>>q;
    for(int i=1;i<=n;i++)cin>>a[i];
    Vertex *root=build(1,n);
    while(q--){
        int ind;cin>>ind;
        switch(ind){
            case 1:int l,r;cin>>l>>r;cout<<get(root,l,r,1,n)<<"\n";break;
            case 2:int pos,nw;cin>>pos>>nw;root=update(root,1,n,pos,nw);break;
            default:break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}
