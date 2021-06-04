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
//number of distinct elements using merge sort tree
struct Node{
    vector<int>vec;
    Node *left,*right;
    Node(int val):left(nullptr),right(nullptr){
        vec.pb(val);
    }
    Node(Node *left,Node *right):left(left),right(right){
        if(left!=nullptr&&right!=nullptr){
            vec.resize(left->vec.size()+right->vec.size());
            merge(left->vec.begin(),left->vec.end(),right->vec.begin(),right->vec.end(),vec.begin());
        }
        if(right==nullptr&&left!=nullptr)vec=left->vec;
        if(left==nullptr&&right!=nullptr)vec=right->vec;
    }
};
int b[200001];
int a[200001];
Node *build(int l,int r){
    if(l==r){
        return new Node(a[l]);
    }
    int m=(l+r)/2;
    return new Node(build(l,m),build(m+1,r));
}

int get(Node *v,int l,int r,int tl,int tr,int x){
    if(l==tl&&r==tr){
        return v->vec.end()-upper_bound(v->vec.begin(),v->vec.end(),x);
    }
    int tm=(tl+tr)/2;
    if(r<=tm)return get(v->left,l,r,tl,tm,x);
    if(l>tm)return get(v->right,l,r,tm+1,tr,x);
    return get(v->left,l,tm,tl,tm,x)+get(v->right,tm+1,r,tm+1,tr,x);
}
vector<int>used(1000001,INT_MAX);
void solve(){
    int n,q;scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
    }
    for(int i=n;i>=1;i--){
        a[i]=used[b[i]];
        used[b[i]]=i;
    }
    Node *root=build(1,n);


    while(q--){
        int l,r;scanf("%d%d",&l,&r);
        printf("%d\n",get(root,l,r,1,n,r));
    }
}

int main(){

    solve();
}
